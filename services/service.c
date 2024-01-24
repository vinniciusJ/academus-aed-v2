//
// Created by nikoly on 13/10/23.
//

#include "headers/service.h"
#include "../models/course.h"
#include "../models/subject.h"
#include "../models/professor.h"
#include "../models/module.h"
#include "../utils/headers/utils.h"

#include "../views/headers/module-view.h"
#include "headers/course-service.h"
#include "../utils/headers/file.h"
#include "../views/headers/views.h"
#include "headers/subject-service.h"
#include "headers/professor-service.h"
#include "headers/module-service.h"

// Lida com a inclusão em lote
// Pré-condição: nenhuma
// Pós-condição: inclusão de dados no arquivo de lote concluida
void insert_in_batch(FILE * file) {
    char type;
    char line[256];

    while(fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, " %c", &type) != 1) {
            continue;
        }

        switch (type) {
            case 'C':
                handle_course(line);
                break;
            case 'D':
                handle_subject(line);
                break;
            case 'P':
                handle_professor(line);
                break;
            case 'M':
                handle_module(line);
                break;
        }
    }

    show_sucess_message("Importação em lote concluída com sucesso!");
}

// Lê os dados de um curso do arquivo de lote e grava no sistema
// Pré-condição: Linha atual ser do tipo Course (caracter C já ter sido lido)
// Pós-condição: inclusão do curso
void handle_course(const char *line) {
    /*FILE * file = open_bin_tree_file("course.bin");
    Course * course = alloc(sizeof(Course));

    sscanf(line, "C;%d;%[^;];%c", &course->code, course->name, &course->area);
    insert_course(*course, file);

    free(course);
    fclose(file);
     */
}

// Lê os dados de uma disciplina do arquivo de lote e grava no sistema
// Pré-condição: Linha atual ser do tipo Subject (caracter D já ter sido lido)
// Pós-condição: inclusão da disciplina
void handle_subject(const char *line) {
    /*FILE * file = open_bin_tree_file("subject.bin");
    Subject * subject = alloc(sizeof(Subject));

    sscanf(line, "D;%d;%[^;];%d;%d", &subject->code, subject->name, &subject->course_code, &subject->year);
    insert_subject(*subject, file);

    free(subject);
    fclose(file);
     /*/
}

// Lê os dados de um professor(a) do arquivo de lote e grava no sistema
// Pré-condição: Linha atual ser do tipo Professor (caracter P já ter sido lido)
// Pós-condição: inclusão do professor(a)
void handle_professor(const char *line) {
    /*FILE * file = open_bin_tree_file("professor.bin");
    Professor * professor = alloc(sizeof(Professor));

    sscanf(line, "P;%d;%[^;]", &professor->code, professor->name);
    insert_professor(*professor, file);

    free(professor);
    fclose(file);
     /*/
}

// Lê os dados de um modulo do arquivo de lote e grava no sistema
// Pré-condição: Linha atual ser do tipo Module (caracter P já ter sido lido)
// Pós-condição: inclusão do professor(a)
void handle_module(const char *line) {
    /*FILE * file = open_bin_tree_file("module.bin");
    Module * module = alloc(sizeof(Module));

    sscanf(line, "M;%d;%d;%d", &module->subject_code, &module->academic_year, &module->professor_code);
    insert_module(*module, file);

    free(module);
    fclose(file);
     /*/
}