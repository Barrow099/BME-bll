//
// Created by barrow099 on 2018.09.05..
//

#ifndef BLL_BLL_H
#define BLL_BLL_H

typedef struct bll_item{
    void * value;
    struct bll_item * next_item;
} bll_item;

typedef struct {
    bll_item* first_item;
    bll_item* last_item;
    int count;
} bll_list;




bll_list* bll_create();
void bll_delete(bll_list * list);
void bll_add(bll_list* list, void* item);
void * bll_get(bll_list *list, int index);
void bll_remove(bll_list * list, int index);

#endif //BLL_BLL_H
