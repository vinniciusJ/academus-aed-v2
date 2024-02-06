//
// Created by nikoly on 13/10/23.
//

#include "headers/service.h"
#include "../models/course.h"
#include "../models/subject.h"
#include "../models/professor.h"
#include "../models/module.h"
#include "../utils/headers/utils.h"
#include "../utils/headers/list.h"

#include "../views/headers/module-view.h"
#include "headers/course-service.h"
#include "../utils/headers/file.h"
#include "../views/headers/views.h"
#include "headers/subject-service.h"
#include "headers/professor-service.h"
#include "headers/module-service.h"
#include "../controllers/headers/course-controller.h"

// Lida com a inclusão em lote
// Pré-condição: nenhuma
// Pós-condição: inclusão de dados no arquivo de lote concluida
void handle_batch_import(FILE * file) {
    char type;
    char line[256];

    while(fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, " %c", &type) != 1) {
            continue;
        }

        switch (type) {
            case 'C':
                handle_course_insertion(line);
                break;
            case 'D':
                handle_subject_insertion(line);
                break;
            case 'P':
               handle_professor_insertion(line);
                break;
//            case 'M':
//                handle_module_insertion(line);
//                break;
//            case 'R':
//                handle_module_deletion(line);
//                break;
            default:
                system(EXIT_SUCCESS);
        }
    }

    show_sucess_message("Importação em lote concluída com sucesso!");
}

// Lê os dados de um curso do arquivo de lote e grava no sistema
// Pré-condição: Linha atual ser do tipo Course (caracter C já ter sido lido)
// Pós-condição: inclusão do curso
void handle_course_insertion(const char *line) {
    FILE * file = open_bin_tree_file("course.bin");
    Header * header = read_header(file);

    Course * course = alloc(sizeof(Course));

    sscanf(line, "C;%d;%[^;];%c", &course->code, course->name, &course->area);

    insert_course(*course, header->root_position, file);

    fclose(file);
}

// Lê os dados de uma disciplina do arquivo de lote e grava no sistema
// Pré-condição: Linha atual ser do tipo Subject (caracter D já ter sido lido)
// Pós-condição: inclusão da disciplina
void handle_subject_insertion(const char *line) {
    FILE * file = open_bin_tree_file("subject.bin");
    Header * header = read_header(file);

    Subject * subject = alloc(sizeof(Subject));

    sscanf(line, "D;%d;%[^;];%d;%d", &subject->code, subject->name, &subject->course_code, &subject->year);
    insert_subject(*subject, header->root_position, file);

    free(subject);
    free(header);
    fclose(file);
}

// Lê os dados de um professor(a) do arquivo de lote e grava no sistema
// Pré-condição: Linha atual ser do tipo Professor (caracter P já ter sido lido)
// Pós-condição: inclusão do professor(a)
void handle_professor_insertion(const char *line) {
    FILE * file = open_bin_tree_file("professor.bin");
    Header * header = read_header(file);

    Professor * professor = alloc(sizeof(Professor));

    sscanf(line, "P;%d;%[^;]", &professor->code, professor->name);
    insert_professor(*professor, header->root_position, file);

    free(professor);
    free(header);
    fclose(file);
}

// Lê os dados de um modulo do arquivo de lote e grava no sistema
// Pré-condição: Linha atual ser do tipo Module (caracter P já ter sido lido)
// Pós-condição: inclusão do professor(a)
void handle_module_insertion(const char *line) {
    FILE * file = open_bin_tree_file("module.bin");
    Header * header = read_header(file);

    Module * module = alloc(sizeof(Module));

    sscanf(line, "M;%d;%d;%d", &module->subject_code, &module->academic_year, &module->professor_code);
    module->code = concatenate_integers(module->academic_year, module->subject_code);

    insert_module(*module, header->root_position, file);

    free(module);
    free(header);
    fclose(file);
}

void handle_module_deletion(const char *line){
    FILE * file = open_bin_tree_file("module.bin");
    Header * header = read_header(file);

    Module * module = alloc(sizeof(Module));

    sscanf(line, "R;%d;%d", &module->subject_code, &module->academic_year);

    remove_module(*module, header->root_position, file);

    free(module);
    free(header);
    fclose(file);
}
