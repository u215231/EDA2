//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/33.manage_posts.h"



void listStringArray (char **StringArray, int SizeArray, char *Who, char *StringType) {

    if (SizeArray == NULL_SIZE) {
        printf("\n%s don't have any %s!\n",Who,StringType);
        return;
    }
    if (SizeArray == ONE_SIZE){
        printf("%s have 1 %s.\n", Who, StringType);
    }
    else{
        printf("%s have %d %ss.\n", Who, SizeArray, StringType);
    }

    for (int i = 0; i < SizeArray; i++) {
        printf("%d. %s\n", i+1, StringArray[i]);
    }
}

void newPost (Network *net, int idx_operating_user) {

    int last = net->user[idx_operating_user].size_posts;

    // Expandim l'estructura de posts.
    net->user->post = expandStringArray(net->user->post, last);
    net->user[idx_operating_user].size_posts += INCREMENT_SIZE;


    // Llegim una string per consola (un nou post).
    printf("\nWrite your new post:\n");
    net->user[idx_operating_user].post[last] = readString();

    // Fem el recompte de les paraules al diccionari.
    read_words(net->dictionary, net->user[idx_operating_user].post[last]);
}

void removePost (Network* net, int idx_operating_user, char **post, int size_posts){

    if(size_posts == NULL_SIZE){
        printf("You don't have any post!\n");
        return;
    }

    int idx_post = readInt("\nWhich post do you want to remove? Write a number of publication (0,1,2...).\n");

    if (idx_post > size_posts){
        printf("\nThat post does not exist!\n");
        return;
    }

    deleteString_InArray(post, size_posts, idx_post);
    net->user[idx_operating_user].size_posts += DECREMENT_SIZE;

    printf("Your post number %d has been removed from your posts!\n", idx_post);
}


void managePostsMenu (Network *net, int idx_operating_user) {

    int option = INVALID_OPTION;

    while(option != OPTION_RETURN_TO_OPERATE_USER_MENU){

        printf("\nMANAGE POSTS MENU\n\n");

        printf("%d. Make a new post.\n", OPTION_NEW_POST);
        printf("%d. List all of my posts.\n", OPTION_LIST_POSTS);
        printf("%d. Remove post.\n",OPTION_REMOVE_POST);

        printf("%d. Return to previous menu.\n",OPTION_RETURN_TO_OPERATE_USER_MENU);
        option = readInt("Choose your option:\n");

        //system("cls");

        char ** post = net->user[idx_operating_user].post;
        int size_posts = net->user[idx_operating_user].size_posts;

        if(option == OPTION_NEW_POST){
            newPost (net,idx_operating_user);
        }
        else if(option == OPTION_LIST_POSTS){
            listStringArray (post,size_posts,"You","post");
        }

        else if(option == OPTION_REMOVE_POST){
            removePost (net, idx_operating_user,post,size_posts);
        }

        else if(option == OPTION_RETURN_TO_OPERATE_USER_MENU){
            ;//DO NOTHING
        }
        else{
            printf("\nInvalid option!\n");
        }

    }
}
