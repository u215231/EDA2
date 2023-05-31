//
// Created by Usuari on 26/4/2023.
//

#include "../Headers/sort_utils.h"

User* merge(User *userA, int sizeA, User *userB, int sizeB, int type){

    User *userC = initUser();
    int a = SET_ZERO, b = SET_ZERO, c = SET_ZERO ;

    while(a!=sizeA && b!=sizeB){

        userC = expandUsers(userC, c);

        if (compAttribute (userA[a],userB[b],type) == LESSTHAN){
            copyUser (&userC[c], &userA[a]); a++;
        }
        else{
            copyUser (&userC[c], &userB[b]); b++;
        }
        c++;
    }

    while(a != sizeA){
        userC = expandUsers(userC, c);
        copyUser (&userC[c], &userA[a]);
        a++; c++;
    }

    while (b != sizeB) {
        userC = expandUsers(userC, c);
        copyUser (&userC[c], &userB[b]);
        b++; c++;
    }
    return userC;
}


User* mergeSort(User *user, int size, int type){

    if (size == ONE_USER)
        return user;

    int mid = size/2;

    User *lowerHalf = &user[0];
    User *upperHalf = &user[mid];

    lowerHalf = mergeSort(lowerHalf, mid, type);
    upperHalf = mergeSort(upperHalf, size - mid, type);

    return merge(lowerHalf, mid, upperHalf, size-mid, type);
}


void sortNetwork (Network *net, int type){

    if(net->size > ONE_USER)
        if(type != net->order)
            net->user = mergeSort (net->user, net->size, type);
    net->order = type;
}

