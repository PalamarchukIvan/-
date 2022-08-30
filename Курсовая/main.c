#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

struct TOVAR{
        char shopName[80];
        char shopAdress[100];
        int productCode;
        char productName[80];
        int productQuantity;
        int productCost;
        int Sum;
        struct TOVAR *next;
    };

struct TOVAR *front;
struct TOVAR *rear;

void Enter();//��������
void Delete();//���������
void Show();//����
void Empty();//���� �������� �������
void Search();//����� ������ �� ��������, ���� �������
void SearchForCheapest();//����� ������������
void Sort();//���������� ������ �� �����
void Edit();//����������� �����
void SpecialDeleteFunc();//��������� ������ �� �������� �����
void Save();//����� ����� �� data.txt �� dataInTable.txt
void load();//������������ ����� � data.txt

int main()
{
    system("chcp 1251");
    system("cls");
    setlocale( LC_ALL, "ukr");
    int choice = 1;
    printf("********************************** \n");
    printf("|   �������  ������ 14-���I���   | \n");
    printf("********************************** \n");
    printf("\n��������Ӫ��� ²������ � ������ �����\n");
    sleep(2);
    system("cls");
    while(choice != 0){
        system("cls");
        printf("�� ��������: \n1 - ������ \n2 - ������� \n3 - �������� \n4 - ����� ������ � ���������(+��������� ���� ������ �� ���������) \n5 - ����� ������������ ������ \n6 - ���������� ������ �� ����� \n7 - �������� \n8 - ��������� ������ �� �������� ����� �� �������\n9 - �������� ���� ����� \n10 - ��������� ��� �� ����� \n0 - ��������� \n");
        scanf("%d", &choice);
        system("cls");
        printf("�� ��������: \n1 - ������ \n2 - ������� \n3 - �������� \n4 - ����� ������ � ���������(+��������� ���� ������ �� ���������) \n5 - ����� ������������ ������ \n6 - ���������� ������ �� ����� \n7 - �������� \n8 - ��������� ������ �� �������� ����� �� �������\n9 - �������� ���� ����� \n10 - ��������� ��� �� ����� \n0 - ��������� \n");
        switch(choice){
            case 1: Enter(); break;
            case 2: Show(); printf("�������� ���� ������"); getch(); system("cls"); break;
            case 3: Delete(); break;
            case 4: Search(); break;
            case 5: SearchForCheapest(); break;
            case 6: Sort(); break;
            case 7: Edit(); break;
            case 8: SpecialDeleteFunc(); break;
            case 9: Save(); break;
            case 10: load(); break;
            case 0: printf("���������� ������\n"); break;
        }
    }
    return 0;
}

void Enter(){
    system("cls");
    struct TOVAR *ptr;

    ptr = (struct TOVAR*)malloc(sizeof(struct TOVAR));
    if(ptr == NULL)
    {
        printf("\������� �������� ���'��\n");
        return;
    }
    else{
        gets(ptr->shopAdress);//���������, ��� �������� �������� gets(). ��� ����� �� �����
        printf("������ ������ ��������: ");
        gets(ptr->shopAdress);

        printf("������ ����� ��������: ");
        gets(ptr->shopName);

        printf("������ ����� ������: ");
        gets(ptr->productName);

        printf("������ ������� ��������: ");
        scanf("%d", &(ptr -> productQuantity));

        printf("������ ������� ��������: ");
        scanf("%d", &(ptr -> productCost));

        printf("������ ��� ��������: ");
        scanf("%d", &(ptr -> productCode));

        ptr->Sum = (ptr->productCost) * (ptr->productQuantity);
        if(front == NULL){//���� ������ �������
            front = ptr;
            rear = ptr;
            front -> next = NULL;
        }
        else{//���� �� ������ �������
            rear -> next = ptr;//����� ��������� ������� ��� ���������� � ��������� (������ ����������)
            rear = ptr;//������� �� ������� ���������
            rear -> next = NULL;//� ��� �� ���������� �������� ����, �� next = NULL
        }
    }
}

void Empty(){
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        printf("   | �����a ��������|  ����� ��������   |   ����� ������  |  ʳ������ ������ | ������� ������ | �������� ������ |    ����    |\n");
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        printf("   |                                                 �����                                                                     |\n");
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        printf("�������� ���� ������");
        getch();
        system("cls");
}

void Delete(){
    struct TOVAR *ptr;
    if(front != NULL){
        ptr = front;
        front = front -> next;//������ �������� ������� �������� �� ���� ������
        free(ptr);//��������� ���������
    }
    else{//� ��� ���� ����� �������
        system("cls");
        Empty();
        return;
    }
}

void Show(){
    system("cls");
    struct TOVAR *ptr;
    int i=1;
    ptr = front;
    if(ptr==NULL){//� ��� ���� ����� �������
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        printf("   | �����a ��������|  ����� ��������   |   ����� ������  |  ʳ������ ������ | ������� ������ | �������� ������ |    ����    |\n");
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        printf("   |                                                 �����                                                                     |\n");
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        return;
    }
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        printf("   | �����a ��������|  ����� ��������   |   ����� ������  |  ʳ������ ������ | ������� ������ | �������� ������ |    ����    |\n");
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
    for(;ptr!=NULL; ptr = ptr -> next, i++){//���� ��� ��������� Ptr �� ������ NULL, �.� �� ������ �� ����� �������, �� ����� �� ��� ���� � �������� �������� ��� �� ������
        printf("%d: |   %s   |      %s      |      %s      |        %d        |       %d       |      %d      |     %d     |\n",
                   i, ptr->shopAdress, ptr->shopName, ptr->productName, ptr -> productQuantity, ptr->productCost, ptr->productCode, ptr->Sum);
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
    }
}

void Search(){
    system("cls");
    struct TOVAR *ptr;
    if(front == NULL){
        Empty();
        return;
    }
    char target[80];
    int i =1;
    gets(target);//���������, ��� �������� �������� gets(). ��� ����� �� �����
    printf("������ ����� ������ ������ ������: ");
    gets(target);
    ptr = front;
    int checkIfFound = 0, sum = 0, choice = 0;
    for(;ptr!=NULL; ptr = ptr -> next, i++){//������ ������� ��� �������
        if(strcmp(ptr->productName, target) == 0){
            printf("%d. �������: %s - �������: %d, ���� - %d\n", i, ptr->shopName, ptr -> productQuantity, ptr->productCost);
            sum += (ptr -> productQuantity) * (ptr -> productCost);//��������� ���� ������
            checkIfFound = 1;
        }
    }
    if(checkIfFound == 0){//���� �� �� ��������� �� �������
        printf("\n����� �� ���� �������� � ��� �����\n\n");
        printf("�������� ���� ������");
        getch();
        system("cls");
        return;
    }
    //� ������ ��'������ ��� ��������, ��� �������� ���� � �������� ������������� ���� ������
    printf("������ ������ �������� ������� ������ �� ��� ���������?(1 - ��, 2 - �) ");
    scanf("%d", &choice);
    if(choice == 1){
        printf("�������� ������� ������ �� ��� ��������� (���. ������ * ����) - %d\n", sum);
    }
    printf("�������� ���� ������");
    getch();
    system("cls");
}

void SearchForCheapest(){
    system("cls");
    struct TOVAR *ptr, *cheapest;
    ptr = front;
    if(ptr == NULL){
        Empty();
            return;
    }
    char target[80];
    int i = 0;
    gets(target);//���������, ��� �������� �������� gets(). ��� ����� �� �����
    printf("������ ����� ������ ������ ������: ");
    gets(target);
    int checkIfFound = 0;
    cheapest = NULL;
    for(;ptr!=NULL; ptr = ptr -> next, i++){
        if(strcmp(ptr->productName, target) == 0 && cheapest == NULL){//����� ������ ������ ��� ������� ����
            cheapest = ptr;
            checkIfFound = 1;//����� ��������
        }
        else if(strcmp(ptr->productName, target) == 0 && (cheapest->productCost) > (ptr->productCost)){//����� ������������ �� ��� ������� (��������� ����������)
            cheapest = ptr;
        }
    }
    if(checkIfFound == 1){
        printf("������� �� ��� � ������� %s �� ������� %s. ������� �� ����� - %d\n", cheapest -> shopName, cheapest->shopAdress, cheapest -> productCost);
    }
    else{
        printf("\n����� ���� ��������\n\n");
    }
    printf("�������� ���� ������");
    getch();
    system("cls");
}

void Sort(){
    system("cls");
    struct TOVAR *ptr/*�������� �� ��������� �������*/, *ptrNext/*�������� �� ���������*/;
    struct TOVAR *ptrTEMP;//������ temp ��� ��������� ����������
    int size, checkForSort = 1, i, choice = 0;
    ptrTEMP = (struct TOVAR*)malloc(sizeof(struct TOVAR));//��������� ���'��� ��� ���������� �����
    if(front == NULL){
        Empty();
        return;
    }
    while(1){
        printf("������� ����������: 1 - �� ����������, 2 - �� ���������\n");
        scanf("%d", &choice);
        if(choice == 1 || choice == 2){
            break;
        }
    }
        /*
            �� �� ����� ������:
            while(checkForSort != 0){
                checkForSort=0
                for(int i = 1; i<size; i++){
                    if(mas[i-1]>mas[i]){
                        temp = mas[i-1];(� ���� ���� ���������� ���� Int ��������� ��� �������� � ������������ ��������� TOVAR)
                        mas[i-1]=mas[i];
                        mas[i] = temp;
                        checkForSort = 1;
                    }
                }
            }
        */
        if(choice == 1){
            while(checkForSort != 0){
                checkForSort = 0;
                ptr = front;
                ptrNext = front-> next;

                while(ptr->next){
                    while(ptrNext != NULL){
                        if((ptr->productCost)>(ptrNext->productCost)){
                                //temp = mas[i-1]
                                strcpy(ptrTEMP->productName, ptr->productName);
                                strcpy(ptrTEMP->shopName, ptr->shopName);
                                strcpy(ptrTEMP->shopAdress, ptr->shopAdress);

                                ptrTEMP->productCost=ptr->productCost;
                                ptrTEMP->productQuantity=ptr->productQuantity;
                                ptrTEMP->productCode=ptr->productCode;
                                ptrTEMP->Sum=ptr->Sum;

                                //mas[i-1]=mas[i];
                                strcpy((ptr->productName), (ptrNext->productName));
                                strcpy((ptr->shopName), (ptrNext->shopName));
                                strcpy((ptr->shopAdress), (ptrNext->shopAdress));

                                ptr->productCost=(ptrNext->productCost);
                                ptr->productQuantity=ptrNext->productQuantity;
                                ptr->productCode=ptrNext->productCode;
                                ptr->Sum=ptrNext->Sum;

                                //mas[i] = temp;
                                strcpy(ptrNext->productName, ptrTEMP->productName);
                                strcpy(ptrNext->shopName, ptrTEMP->shopName);
                                strcpy(ptrNext->shopAdress, ptrTEMP->shopAdress);

                                ptrNext->productCost=ptrTEMP->productCost;
                                ptrNext->productQuantity=ptrTEMP->productQuantity;
                                ptrNext->productCode=ptrTEMP->productCode;
                                ptrNext->Sum=ptrTEMP->Sum;

                                checkForSort++;
                        }
                        //������� �� ���������� ��������
                        ptr=ptr->next;
                        ptrNext = ptrNext->next;
                    }
                }
            }
        }
        else if(choice == 2){
            while(checkForSort != 0){
                checkForSort = 0;
                ptr = front;
                ptrNext = front-> next;

                while(ptr->next){
                    while(ptrNext != NULL){
                        if((ptr->productCost)<(ptrNext->productCost)){
                                //temp = mas[i-1]
                                strcpy(ptrTEMP->productName, ptr->productName);
                                strcpy(ptrTEMP->shopName, ptr->shopName);
                                strcpy(ptrTEMP->shopAdress, ptr->shopAdress);

                                ptrTEMP->productCost=ptr->productCost;
                                ptrTEMP->productQuantity=ptr->productQuantity;
                                ptrTEMP->productCode=ptr->productCode;
                                ptrTEMP->Sum=ptr->Sum;

                                //mas[i-1]=mas[i];
                                strcpy((ptr->productName), (ptrNext->productName));
                                strcpy((ptr->shopName), (ptrNext->shopName));
                                strcpy((ptr->shopAdress), (ptrNext->shopAdress));

                                ptr->productCost=(ptrNext->productCost);
                                ptr->productQuantity=ptrNext->productQuantity;
                                ptr->productCode=ptrNext->productCode;
                                ptr->Sum=ptrNext->Sum;

                                //mas[i] = temp;
                                strcpy(ptrNext->productName, ptrTEMP->productName);
                                strcpy(ptrNext->shopName, ptrTEMP->shopName);
                                strcpy(ptrNext->shopAdress, ptrTEMP->shopAdress);

                                ptrNext->productCost=ptrTEMP->productCost;
                                ptrNext->productQuantity=ptrTEMP->productQuantity;
                                ptrNext->productCode=ptrTEMP->productCode;
                                ptrNext->Sum=ptrTEMP->Sum;

                                checkForSort++;
                        }
                        //������� �� ���������� ��������
                        ptr=ptr->next;
                        ptrNext = ptrNext->next;
                    }
                }
            }
        }
    free(ptrTEMP);//��������� �������� ���'���
    system("cls");
}

void Edit(){
    system("cls");
    struct TOVAR *ptr;
    int target;
    int choice, i, size, checkIfFound, checkForNextTry = 1, checkIfCorrect;
    if(front == NULL){
        Empty();
        return;
    }
    for(ptr = front; ptr!=NULL; ptr = ptr->next){//����� ������ ������. � ���������� ���� ����������� ��� ������ ��������������� ��� �������
        size++;
    }

    do{//��������� ��� ��������� �������� � �� ������ ��������
        system("cls");
        Show();
        do{//���� �� ��������� ����� �����
            printf("������ ����� ����� ���� ������� ����������: ");
            scanf("%d", &choice);
            if(choice>size || choice<=0){
                printf("\n���� ������ ��������\n");
            }
            else{
                checkIfFound = 1;//������� ��������
            }
        }while(checkIfFound == 0);

        ptr = front;
        for(i = 1; i<choice; i++){//����������� �� ������ ����������� �������
            ptr = ptr->next;
        }
        checkIfCorrect = 0;
        printf("\n");
        do{//�������� ��� �������� �������� ��� ������ ����������
            do{//���� �� ��������� ����� ���������
                printf("\n������� �������� ��� ����������� ");
                printf("\n1 - ������ \n2 - ����� �������� \n3 - ����� ������ \n4 - ʳ������ ������ \n5 - ������� ������ \n6 - ��������\n");
                scanf("%d", &target);
                if(target>0 && target < 7){
                    checkIfCorrect = 1;//����� ��� ���������
                }
                else{
                    printf("\n�������, ������� ���� �� ������������� \n");
                }

            }while(checkIfCorrect == 0);

            switch(target){//������ ��������
                case 1:
                    printf("������ ���� ������: ");
                    gets(ptr->shopAdress);
                    gets(ptr->shopAdress);
                break;

                case 2:
                    printf("������ ���� ����� ��������: ");
                    gets(ptr->shopName);
                    gets(ptr->shopName);
                break;

                case 3:
                    printf("������ ���� ����� ������: ");
                    gets(ptr->productName);
                    gets(ptr->productName);
                break;

                case 4:
                    printf("������ ���� ʳ������ ������: ");
                    scanf("%d", &(ptr->productQuantity));
                    ptr->Sum = (ptr->productQuantity) * (ptr->productCost);//��� ��� ������� ��������� � �������� ��������
                break;

                case 5:
                    printf("������ ���� ������� ������: ");
                    scanf("%d", &(ptr->productCost));
                    ptr->Sum = (ptr->productQuantity) * (ptr->productCost);//��� ��� ���� ��������� � �������� ��������
                break;

                case 6:
                    printf("������ ����� ��������: ");
                    scanf("%d", &(ptr->productCode));
                break;
            }
            printf("\n������ ������������ �� ���� ��������? (1-��, 2-�) ");
            scanf("%d", &choice);
        }while(choice == 1);
        printf("\n������ ������������ �� ���� �������? (1-��, 2-�) ");
        scanf("%d", &checkForNextTry);
    }while(checkForNextTry == 1);
    printf("�������� ���� ������");
    getch();
    system("cls");
}

void SpecialDeleteFunc(){
    system("cls");
    struct TOVAR *ptr, *ptrTemp, *ptrPreRear;
    int target, size;
    ptr = front;
    if(ptr==NULL){
        Empty();
        return;
    }
    printf("������ ����, ������ � ���� ������ ������: ");
    scanf("%d", &target);
    int checkForSort = 1, checkIfWas = 0;
    if(front->next == NULL && front->productCost == target){//���� �� ������ ������� � �� � ����� �����
        free(rear);
        rear = NULL;
        front = NULL;
        printf("�������� ���� ������");
        getch();
        system("cls");
        return;
    }
    else if(front->next == NULL && front->productCost != target){//���� �� ������ ������� � �� �� � ����� �����
        printf("����� � ����� ����� �� ��� ��������� \n");
        printf("�������� ���� ������");
        getch();
        system("cls");
        return;
    }
    for(;ptr->next!=NULL; ptr = ptr->next){
        while(checkForSort == 1){//�������� ��� ������������, � ������� ���� �� ����������� ����� �������
            checkForSort = 0;
            if(ptr->next->productCost == target && ptr->next!=rear){
                ptrTemp = ptr->next;
                ptr->next = ptr->next->next;
                free(ptrTemp);
                checkForSort = 1;
                checkIfWas = 2;
            }
            if(ptr ->next == rear){
                ptrPreRear = ptr;
            }
        }
        checkForSort = 1;
    }
    if(rear ->productCost == target){//� ������� ���� ���� ���� ������� �����
        free(rear);
        rear = ptrPreRear;
        ptrPreRear->next = NULL;
        checkIfWas = 2;
    }
    if(rear == front && front ->productCost == target){//� �������, ���� ���� ��� �������� ������� ���� ������� � �� � ���� ����
        free(rear);
        rear = NULL;
        front = NULL;
        checkIfWas = 2;
    }
    else if(front->productCost == target && front != rear){//���� ���a ���� ���� �����
        ptrTemp = front;
        front = front ->next;
        free(ptrTemp);
        checkIfWas = 2;
    }
    if(checkIfWas == 0){
        printf("����� � ����� ����� �� ��� ��������� \n");
    }
    printf("�������� ���� ������");
    getch();
    system("cls");
}


void Save(){
    struct TOVAR *ptr;

    FILE *file;
    FILE *userFriendly;

    file = fopen("data.txt", "w");
    userFriendly = fopen("dataInTable.txt", "w");

    if(file == NULL || userFriendly == NULL){
        printf("ERROR");
        getch();
        return;
    }
    ptr = front;
    int i = 0;
    if(ptr==NULL){//���� ������ �������
        fprintf(file, "0 ");
        fseek(file, 0, SEEK_CUR);
        return;
    }

    fprintf(file, "%d ", i);//���������� ���� �� ����� ������� ������
    fseek(file, 0, SEEK_CUR);
    for(;ptr!=NULL; ptr = ptr -> next, i++){//����� ���� ����� � ���� data.txt
        fprintf(file, "�����a: %s\n\0", ptr->shopAdress);
        fseek(file, 0, SEEK_CUR);
        fprintf(file, "�������: %s\n\0", ptr->shopName);
        fseek(file, 0, SEEK_CUR);
        fprintf(file, "�������: %s\n\0", ptr->productName);
        fseek(file, 0, SEEK_CUR);
        fprintf(file, "ʳ������: %d\n\0", ptr->productQuantity);
        fseek(file, 0, SEEK_CUR);
        fprintf(file, "�������: %d\n\0", ptr->productCost);
        fseek(file, 0, SEEK_CUR);
        fprintf(file, "��������: %d\n\0", ptr->productCode);
        fseek(file, 0, SEEK_CUR);
        fprintf(file, "����: %d\n\0", ptr->Sum);
        fseek(file, 0, SEEK_CUR);
    }
    fseek(file, 0, SEEK_SET);
    fprintf(file, "%d ", i);//����� ������� ������
    fseek(file, 0, SEEK_CUR);

    //����� �� ����� dataInTable.txt
    fprintf(userFriendly, "   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
    fseek(userFriendly, 0, SEEK_CUR);
    fprintf(userFriendly, "   | �����a ��������|  ����� ��������   |   ����� ������  |  ʳ������ ������ | ������� ������ | �������� ������ |    ����    |\n");
    fseek(userFriendly, 0, SEEK_CUR);
    fprintf(userFriendly, "   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
    fseek(userFriendly, 0, SEEK_CUR);
    for(ptr = front;ptr!=NULL; ptr = ptr -> next, i++){//���� ��� ��������� Ptr �� ������ NULL, �.� �� ������ �� ����� �������, �� ����� �� ��� ���� � �������� �������� ��� �� ������
        fprintf(userFriendly, "%d: |   %s   |      %s      |      %s      |        %d        |       %d       |      %d      |     %d     |\n",
                   i, ptr->shopAdress, ptr->shopName, ptr->productName, ptr -> productQuantity, ptr->productCost, ptr->productCode, ptr->Sum);
        fseek(userFriendly, 0, SEEK_CUR);
        fprintf(userFriendly, "   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        fseek(userFriendly, 0, SEEK_CUR);
    }
}

void load(){
    struct TOVAR *ptr;
    char Buffer[100];

    FILE *file;
    file = fopen("data.txt", "r");

    if(file== NULL){
        printf("ERROR");
        getch();
        return;
    }

    while(front!=NULL){//��������� ���� ����� �� ���� �� �����
        Delete();
    }

    ptr = front;
    int N;
    fscanf(file, "%d ", &N);//���������� ������ ������
    fseek(file, 0, SEEK_CUR);

    for(int i = 0; i<N; i++){//����� ����� �� ���������
        ptr = (struct TOVAR*)malloc(sizeof(struct TOVAR));
        if(ptr == NULL)
        {
            printf("\������ �������� ���'���\n");
            return;
        }
        else{
            fscanf(file, "%s ", &Buffer);//�� ������ ���������� �������� �� ����� ��� �� �� ���������. ���������: �������: �������� 7, '�������:' - ���������� � Buffeer
            fseek(file, 0, SEEK_CUR);
            fgets(ptr->shopAdress, sizeof(ptr->shopAdress), file);
            fseek(file, 0, SEEK_CUR);

            for(int j = 0; j<sizeof(ptr->shopAdress); j++){//�������� ��� ��������� ������ ���� �����
                if(ptr->shopAdress[j] == '\n'){
                    ptr->shopAdress[j] = '\0';
                }
            }
            fscanf(file, "%s ", &Buffer);
            fseek(file, 0, SEEK_CUR);
            fgets(ptr->shopName, sizeof(ptr->shopName), file);
            fseek(file, 0, SEEK_CUR);

            for(int j = 0; j<sizeof(ptr->shopName); j++){
                if(ptr->shopName[j] == '\n'){
                    ptr->shopName[j] = '\0';
                }
            }

            fscanf(file, "%s ", &Buffer);
            fseek(file, 0, SEEK_CUR);
            fgets(ptr->productName, sizeof(ptr->productName), file);
            fseek(file, 0, SEEK_CUR);

            for(int j = 0; j<sizeof(ptr->productName); j++){
                if(ptr->productName[j] == '\n'){
                    ptr->productName[j] = '\0';
                }
            }

            fscanf(file, "%s ", &Buffer);
            fseek(file, 0, SEEK_CUR);
            fscanf(file, "%d\n", &ptr->productQuantity);
            fseek(file, 0, SEEK_CUR);

            fscanf(file, "%s ", &Buffer);
            fseek(file, 0, SEEK_CUR);
            fscanf(file, "%d\n", &ptr->productCost);
            fseek(file, 0, SEEK_CUR);

            fscanf(file, "%s ", &Buffer);
            fseek(file, 0, SEEK_CUR);
            fscanf(file, "%d\n", &ptr->productCode);
            fseek(file, 0, SEEK_CUR);

            fscanf(file, "%s ", &Buffer);
            fseek(file, 0, SEEK_CUR);
            fscanf(file, "%d\n", &ptr->Sum);
            fseek(file, 0, SEEK_CUR);

            if(front == NULL){//���� �� ������ �������
                front = ptr;
                rear = ptr;
                front -> next = NULL;
            }
            else{//���� �� ������
                rear -> next = ptr;
                rear = ptr;
                rear -> next = NULL;
            }
        }
    }
}
