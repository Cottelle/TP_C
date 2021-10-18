#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char * name;
    int birthYear;
    int id;
} Student;

Student *student_create(void){
    Student *eleve = malloc(sizeof(Student));
    if (eleve==NULL){
        free(eleve);
        return NULL;
    }
    char *nom=malloc(1000);
        if(nom==NULL){
            free(nom);
            free(eleve);
            return NULL;
        }
    fgets(nom,1000,stdin);
    int y,n;
    scanf("%i",&y);
    scanf("%i",&n);
    eleve->name=nom;
    eleve->birthYear=y;
    eleve->id=n;
    return eleve;

}

void student_print(Student * s){
    printf("id:        %i\n",s->id);
    printf("name:      ");
    for(int i=0;s->name[i]!='\0';i++){
        printf("%c",s->name[i]);
    }
    printf("birthYear: %i\n",s->birthYear);
}

void student_free(Student *s){
    if (s!=NULL){
    free(s->name);
    free(s);
}}