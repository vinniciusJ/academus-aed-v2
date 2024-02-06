//
// Created by vinniciusj on 14/09/23.
//

#ifndef ACADEMUS_HEADER_H
#define ACADEMUS_HEADER_H

#define MAX_FREE_POSITIONS 100

typedef struct {
    int root_position;
    int top_position;
    int free_positions[MAX_FREE_POSITIONS];
    int num_free_positions;
} Header;

#endif //ACADEMUS_HEADER_H
