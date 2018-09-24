//
//  structure_manager.c
//  esercizi_sistemi_operativi_c
//
//  Created by Elia Migliore on 01/11/17.
//  Copyright © 2017 Elia Migliore. All rights reserved.
//

#include  <sys/types.h>
#include  <sys/stat.h>
#include  <fcntl.h>
#include  <dirent.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <unistd.h>

/*
 list for string structure
*/
struct list {
    struct list *child;
    char* string;
};

/*
 add a string to the list
*/
void list_push_element(struct list *my_list,char* string){
    if (my_list->child != NULL)
        list_push_element(my_list->child, string);
    else {
        my_list->child = malloc(sizeof(struct list));
        my_list->child->string = string;
        my_list->child->child = NULL;
    }
}

/*
 see below
*/
struct list* list_position_at_r(struct list *my_list,int pos,int x){
    if (pos == x)
        return my_list;
    
    return list_position_at_r(my_list, pos,x+1);
}

/*
 return the element of the list
 at the position given
*/
struct list* list_position_at(struct list *my_list,int pos){
    return list_position_at_r(my_list,pos,0);
}

/*
 see below
*/
int list_count_r(struct list *my_list,int x){
    if (my_list->child == NULL)
        return x;
    return list_count_r(my_list, x+1);
}

/*
 return the number of element
 inside the list
*/
int list_count(struct list *my_list){
    return list_count_r(my_list,0);
}

/*
 add an element to the list
*/
char* list_pop_element(struct list *my_list){
    int size = list_count(my_list);
    if (size > 0)
        my_list = list_position_at(my_list, size-1);
    
    char* string = my_list->string;
    free(my_list);
    return string;
}

/*
 method only for indent the output
*/
void indent(int recursion_level){
    printf("\n");int x;
    for(x = 0;x < recursion_level;x++)
        printf("   ");
}

/*
 return type:
 -1 : file not exist
 0 : is a directory
 1 : is a file
 
*/
int path_type(char *path){
    
    struct stat entryType;
    
    if(lstat(path,&entryType)<0){
        return -1;
    }
    
    if(S_ISDIR(entryType.st_mode)==0){
        return 0;
    }
    
    return 1;
}

/*
 
 verify if the path is a directory, if not exit from
 the program with error
 
*/
void verify_is_directory(char* path){
    
    int path_t = path_type(path);
    
    if (path_t == 0){
        printf("error! the path %s is not a directory",path);
        exit(1);
    }
    if (path_t == -1){
        printf("error! the path %s not exist",path);
        exit(1);
    }
}

/*
 see below
*/
void read_dir_r(struct list *my_list,char* path,int recursion_level){
    
    // return if i'm not a directory
    if (path_type(path) != 1)
        return;
    
    
    // structure for managing data for directory
    DIR* directory_ingress_puntator = NULL;
    struct dirent *directory_ingress = NULL;
    
    // assignement data to the structure
    directory_ingress_puntator = opendir(path);
    directory_ingress = readdir(directory_ingress_puntator);
    
    if(directory_ingress_puntator == NULL){
        printf("\nerror during the file reading");
    }
    
    
    // data for reading directory content and recursion
    int len = strlen(path)+1;
    char BUFFER[255];
    strcpy(BUFFER, path);
    BUFFER[len-1] = '/';
    
    while ((directory_ingress = readdir(directory_ingress_puntator)) != NULL) {
        // do not working use . and .. puntator
        if (strcmp(directory_ingress->d_name, "..") == 0 || strcmp(directory_ingress->d_name, ".") == 0)
            continue;
        
        // printing and listing location
        indent(recursion_level);
        strcpy(&BUFFER[len], directory_ingress->d_name);
        printf ("DEGUB: %s", BUFFER);
        list_push_element(my_list, strdup(BUFFER));
        
        
        // code for recursion
        read_dir_r(my_list,BUFFER,recursion_level+1);
    }
}

/*
 take as argument a list supposed void
 a path and return the list filled by the
 path and the child path of the path
 */
struct list *read_dir(char* path){
    struct list *my_list = calloc(1, sizeof(struct list));
    read_dir_r(my_list,path, 0);
    return my_list;
}

void read_list(struct list *my_list){
    if (my_list->child != NULL)
        read_list(my_list->child);
    
    printf("\n %s",my_list->string);
}

void free_list(struct list *my_list){
    if (my_list->child != NULL)
        free_list(my_list->child);
    
    free(my_list);
}

int main(int argc,char* argv[]){
    
    if (argc != 2){
        printf("number of argument wrong!");
    }
    
    // code for data validation
    //verify_is_directory(argv[1]);
    
    
    // read of the directory
    struct list *my_list = read_dir("/Volumes/RAM Disk/Lab02_Es02");
    read_list(my_list);
    free_list(my_list);
    
}










