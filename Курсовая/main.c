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

void Enter();//Введення
void Delete();//Видалення
void Show();//Вивід
void Empty();//Вивід порожньої таблиці
void Search();//Пошук товару по магазину, вивід кількості
void SearchForCheapest();//Пошук найдешевшого
void Sort();//Сортування товару за ціною
void Edit();//Редагування даних
void SpecialDeleteFunc();//Видалення товарів за вказаною ціною
void Save();//Запис даних до data.txt та dataInTable.txt
void load();//Завантаження даних з data.txt

int main()
{
    system("chcp 1251");
    system("cls");
    setlocale( LC_ALL, "ukr");
    int choice = 1;
    printf("********************************** \n");
    printf("|   КУРСОВА  РОБОТА 14-ВАРIАНТ   | \n");
    printf("********************************** \n");
    printf("\nРЕКОМЕНДУЄТСЯ ВІДКРИТИ В ПОВНИЙ ЭКРАН\n");
    sleep(2);
    system("cls");
    while(choice != 0){
        system("cls");
        printf("Що виконати: \n1 - ввести \n2 - вивести \n3 - видалити \n4 - пошук товару в магазинах(+підрахунок суми товару по магазинам) \n5 - поиск найдешевшого товару \n6 - Сортування товару за ціною \n7 - Редакція \n8 - Видалення записів із вказаною ціною за одиницю\n9 - Зберегти базу даних \n10 - Загрузити дані із файлу \n0 - Завершити \n");
        scanf("%d", &choice);
        system("cls");
        printf("Що виконати: \n1 - ввести \n2 - вивести \n3 - видалити \n4 - пошук товару в магазинах(+підрахунок суми товару по магазинам) \n5 - поиск найдешевшого товару \n6 - Сортування товару за ціною \n7 - Редакція \n8 - Видалення записів із вказаною ціною за одиницю\n9 - Зберегти базу даних \n10 - Загрузити дані із файлу \n0 - Завершити \n");
        switch(choice){
            case 1: Enter(); break;
            case 2: Show(); printf("Натисніть любу клавішу"); getch(); system("cls"); break;
            case 3: Delete(); break;
            case 4: Search(); break;
            case 5: SearchForCheapest(); break;
            case 6: Sort(); break;
            case 7: Edit(); break;
            case 8: SpecialDeleteFunc(); break;
            case 9: Save(); break;
            case 10: load(); break;
            case 0: printf("Завершення роботи\n"); break;
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
        printf("\Помилка виділення пом'яті\n");
        return;
    }
    else{
        gets(ptr->shopAdress);//Зробленно, щоб коректно працював gets(). Без цього не сканує
        printf("Введіть адресу магазина: ");
        gets(ptr->shopAdress);

        printf("Введіть назву магазина: ");
        gets(ptr->shopName);

        printf("Введіть назву товара: ");
        gets(ptr->productName);

        printf("Введіть кількість продукта: ");
        scanf("%d", &(ptr -> productQuantity));

        printf("Введіть варітсть продукта: ");
        scanf("%d", &(ptr -> productCost));

        printf("Введіть код продукта: ");
        scanf("%d", &(ptr -> productCode));

        ptr->Sum = (ptr->productCost) * (ptr->productQuantity);
        if(front == NULL){//Якщо перший елемент
            front = ptr;
            rear = ptr;
            front -> next = NULL;
        }
        else{//Якщо не перший елемент
            rear -> next = ptr;//Тепер наступний елемент для останнього є теперешній (список розширився)
            rear = ptr;//останнім ми вважаємо теперешній
            rear -> next = NULL;//і так як наступного елемента немає, то next = NULL
        }
    }
}

void Empty(){
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        printf("   | Адресa магазина|  Назва магазина   |   Назва товара  |  Кількість товару | Вартість товару | Артикуль товару |    Сума    |\n");
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        printf("   |                                                 ПУСТО                                                                     |\n");
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        printf("Натисніть любу клавішу");
        getch();
        system("cls");
}

void Delete(){
    struct TOVAR *ptr;
    if(front != NULL){
        ptr = front;
        front = front -> next;//зміщуємо покажчик першого елементу на один вперед
        free(ptr);//видаляємо попередній
    }
    else{//у разі коли черга порожня
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
    if(ptr==NULL){//у разі коли черга порожня
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        printf("   | Адресa магазина|  Назва магазина   |   Назва товара  |  Кількість товару | Вартість товару | Артикуль товару |    Сума    |\n");
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        printf("   |                                                 ПУСТО                                                                     |\n");
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        return;
    }
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
        printf("   | Адресa магазина|  Назва магазина   |   Назва товара  |  Кількість товару | Вартість товару | Артикуль товару |    Сума    |\n");
        printf("   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
    for(;ptr!=NULL; ptr = ptr -> next, i++){//пока наш указатель Ptr не станет NULL, т.е не дойдет до конца Очереди, мы будем по ней идти и выводить значение что он хранит
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
    gets(target);//Зробленно, щоб коректно працював gets(). Без цього не сканує
    printf("Введіть товар котрий бажаєте знайти: ");
    gets(target);
    ptr = front;
    int checkIfFound = 0, sum = 0, choice = 0;
    for(;ptr!=NULL; ptr = ptr -> next, i++){//шукаємо цікавий нам продукт
        if(strcmp(ptr->productName, target) == 0){
            printf("%d. Магазин: %s - кількість: %d, ціна - %d\n", i, ptr->shopName, ptr -> productQuantity, ptr->productCost);
            sum += (ptr -> productQuantity) * (ptr -> productCost);//підрахунок суми товару
            checkIfFound = 1;
        }
    }
    if(checkIfFound == 0){//якщо ми не натрапили на елемент
        printf("\nТовар не було знайдено в базі даних\n\n");
        printf("Натисніть любу клавішу");
        getch();
        system("cls");
        return;
    }
    //Я вирішив об'єднати два завдання, мені задалося вони є логічними продовженнями один одного
    printf("Бажаєте знайти загальну вартість товару по усім магазинам?(1 - да, 2 - ні) ");
    scanf("%d", &choice);
    if(choice == 1){
        printf("Загальну вартість товару по усім магазинам (кіль. товара * ціну) - %d\n", sum);
    }
    printf("Натисніть любу клавішу");
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
    gets(target);//Зробленно, щоб коректно працював gets(). Без цього не сканує
    printf("Введіть товар котрий бажаєте знайти: ");
    gets(target);
    int checkIfFound = 0;
    cheapest = NULL;
    for(;ptr!=NULL; ptr = ptr -> next, i++){
        if(strcmp(ptr->productName, target) == 0 && cheapest == NULL){//пошук нашого товару для першого разу
            cheapest = ptr;
            checkIfFound = 1;//товар знайдено
        }
        else if(strcmp(ptr->productName, target) == 0 && (cheapest->productCost) > (ptr->productCost)){//Пошук найдешевшого не для першого (порівняння зпопереднім)
            cheapest = ptr;
        }
    }
    if(checkIfFound == 1){
        printf("Дешевше за все в магазині %s за адресою %s. Вартість за штуку - %d\n", cheapest -> shopName, cheapest->shopAdress, cheapest -> productCost);
    }
    else{
        printf("\nТовар було знайдено\n\n");
    }
    printf("Натисніть любу клавішу");
    getch();
    system("cls");
}

void Sort(){
    system("cls");
    struct TOVAR *ptr/*Покажчик на теперешній елемент*/, *ptrNext/*Покажчик на наступний*/;
    struct TOVAR *ptrTEMP;//Аналог temp при сортуванні бульбашкою
    int size, checkForSort = 1, i, choice = 0;
    ptrTEMP = (struct TOVAR*)malloc(sizeof(struct TOVAR));//Тимчасова пам'ять для збереження даних
    if(front == NULL){
        Empty();
        return;
    }
    while(1){
        printf("Выберіть сорутвання: 1 - за зростанням, 2 - за спаданням\n");
        scanf("%d", &choice);
        if(choice == 1 || choice == 2){
            break;
        }
    }
        /*
            Те що знизу аналог:
            while(checkForSort != 0){
                checkForSort=0
                for(int i = 1; i<size; i++){
                    if(mas[i-1]>mas[i]){
                        temp = mas[i-1];(в роли этих переменных типа Int выступают все значения в динамической структуре TOVAR)
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
                        //Зміщення до наступного елементу
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
                        //Зміщення до наступного елементу
                        ptr=ptr->next;
                        ptrNext = ptrNext->next;
                    }
                }
            }
        }
    free(ptrTEMP);//Звільнюємо динамічну пам'ять
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
    for(ptr = front; ptr!=NULL; ptr = ptr->next){//Пошук розміру масиву. У подальшому буде використано для пошуку позиціїцікавого нам елменту
        size++;
    }

    do{//Робииться для можливості редакціх і ще одного елементу
        system("cls");
        Show();
        do{//Тест на коректний запис рядку
            printf("Введіть номер рядку який потрібно редагувати: ");
            scanf("%d", &choice);
            if(choice>size || choice<=0){
                printf("\nНемає такого елементу\n");
            }
            else{
                checkIfFound = 1;//елемент знайдено
            }
        }while(checkIfFound == 0);

        ptr = front;
        for(i = 1; i<choice; i++){//Переміщуємося на цікаву користувачу позицію
            ptr = ptr->next;
        }
        checkIfCorrect = 0;
        printf("\n");
        do{//Робиться для моливості редакції іще одного опараметру
            do{//Тест на коректний запис параметру
                printf("\nВиберіть параметр для редагування ");
                printf("\n1 - Адреса \n2 - Назва магазину \n3 - Назва товару \n4 - Кількість товару \n5 - Вартість товару \n6 - Артикуль\n");
                scanf("%d", &target);
                if(target>0 && target < 7){
                    checkIfCorrect = 1;//запис був коректний
                }
                else{
                    printf("\nПомилка, виберіть щось із перечисленого \n");
                }

            }while(checkIfCorrect == 0);

            switch(target){//Власне редакція
                case 1:
                    printf("Введіть нову Адресу: ");
                    gets(ptr->shopAdress);
                    gets(ptr->shopAdress);
                break;

                case 2:
                    printf("Введіть нову Назву магазина: ");
                    gets(ptr->shopName);
                    gets(ptr->shopName);
                break;

                case 3:
                    printf("Введіть нову Назву товара: ");
                    gets(ptr->productName);
                    gets(ptr->productName);
                break;

                case 4:
                    printf("Введіть нову Кількість товара: ");
                    scanf("%d", &(ptr->productQuantity));
                    ptr->Sum = (ptr->productQuantity) * (ptr->productCost);//При зміні кількості змінюється і загальна ввартість
                break;

                case 5:
                    printf("Введіть нову Вартість товара: ");
                    scanf("%d", &(ptr->productCost));
                    ptr->Sum = (ptr->productQuantity) * (ptr->productCost);//При зміні ціни змінюється і загальна ввартість
                break;

                case 6:
                    printf("Введіть новий Артикуль: ");
                    scanf("%d", &(ptr->productCode));
                break;
            }
            printf("\nБажаєте відредагувати ще один параметр? (1-да, 2-ні) ");
            scanf("%d", &choice);
        }while(choice == 1);
        printf("\nБажаєте відредагувати ще один елемент? (1-да, 2-ні) ");
        scanf("%d", &checkForNextTry);
    }while(checkForNextTry == 1);
    printf("Натисніть любу клавішу");
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
    printf("Введіть ціну, записи з якою будуть вдалені: ");
    scanf("%d", &target);
    int checkForSort = 1, checkIfWas = 0;
    if(front->next == NULL && front->productCost == target){//якщо це єдиний елемент і він є нашою ціллю
        free(rear);
        rear = NULL;
        front = NULL;
        printf("Натисніть любу клавішу");
        getch();
        system("cls");
        return;
    }
    else if(front->next == NULL && front->productCost != target){//якщо це єдиний елемент і він не є нашою ціллю
        printf("Товар з такою ціною не був знайдений \n");
        printf("Натисніть любу клавішу");
        getch();
        system("cls");
        return;
    }
    for(;ptr->next!=NULL; ptr = ptr->next){
        while(checkForSort == 1){//робиться для переперевірки, у випадку коли ми перескочимо через елемент
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
    if(rear ->productCost == target){//У випадку коли наша ціль останній товар
        free(rear);
        rear = ptrPreRear;
        ptrPreRear->next = NULL;
        checkIfWas = 2;
    }
    if(rear == front && front ->productCost == target){//У випадку, якщо після всіх видалень остався один елемент і він є наша ціль
        free(rear);
        rear = NULL;
        front = NULL;
        checkIfWas = 2;
    }
    else if(front->productCost == target && front != rear){//Якшо нашa ціль була перша
        ptrTemp = front;
        front = front ->next;
        free(ptrTemp);
        checkIfWas = 2;
    }
    if(checkIfWas == 0){
        printf("Товар з такою ціною не був знайдений \n");
    }
    printf("Натисніть любу клавішу");
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
    if(ptr==NULL){//Якщо список порожній
        fprintf(file, "0 ");
        fseek(file, 0, SEEK_CUR);
        return;
    }

    fprintf(file, "%d ", i);//Виділяється місце під запис довжини списку
    fseek(file, 0, SEEK_CUR);
    for(;ptr!=NULL; ptr = ptr -> next, i++){//запис бази даних у файл data.txt
        fprintf(file, "Адресa: %s\n\0", ptr->shopAdress);
        fseek(file, 0, SEEK_CUR);
        fprintf(file, "Магазин: %s\n\0", ptr->shopName);
        fseek(file, 0, SEEK_CUR);
        fprintf(file, "Продукт: %s\n\0", ptr->productName);
        fseek(file, 0, SEEK_CUR);
        fprintf(file, "Кількість: %d\n\0", ptr->productQuantity);
        fseek(file, 0, SEEK_CUR);
        fprintf(file, "Варітсть: %d\n\0", ptr->productCost);
        fseek(file, 0, SEEK_CUR);
        fprintf(file, "Артикуль: %d\n\0", ptr->productCode);
        fseek(file, 0, SEEK_CUR);
        fprintf(file, "Сума: %d\n\0", ptr->Sum);
        fseek(file, 0, SEEK_CUR);
    }
    fseek(file, 0, SEEK_SET);
    fprintf(file, "%d ", i);//запис довжини списку
    fseek(file, 0, SEEK_CUR);

    //запис до файлу dataInTable.txt
    fprintf(userFriendly, "   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
    fseek(userFriendly, 0, SEEK_CUR);
    fprintf(userFriendly, "   | Адресa магазина|  Назва магазина   |   Назва товара  |  Кількість товару | Вартість товару | Артикуль товару |    Сума    |\n");
    fseek(userFriendly, 0, SEEK_CUR);
    fprintf(userFriendly, "   +----------------+-------------------+-----------------+-------------------+-----------------+-----------------+------------+\n");
    fseek(userFriendly, 0, SEEK_CUR);
    for(ptr = front;ptr!=NULL; ptr = ptr -> next, i++){//пока наш указатель Ptr не станет NULL, т.е не дойдет до конца Очереди, мы будем по ней идти и выводить значение что он хранит
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

    while(front!=NULL){//видалення бази даних що була до цього
        Delete();
    }

    ptr = front;
    int N;
    fscanf(file, "%d ", &N);//сканування розміру масива
    fseek(file, 0, SEEK_CUR);

    for(int i = 0; i<N; i++){//запис даних до структури
        ptr = (struct TOVAR*)malloc(sizeof(struct TOVAR));
        if(ptr == NULL)
        {
            printf("\Ошибка виділення пам'яти\n");
            return;
        }
        else{
            fscanf(file, "%s ", &Buffer);//до зміннної заноситься значення що описує дані які ми загружаємо. Наприклад: Адресса: Бочарова 7, 'Адресса:' - заноситься у Buffeer
            fseek(file, 0, SEEK_CUR);
            fgets(ptr->shopAdress, sizeof(ptr->shopAdress), file);
            fseek(file, 0, SEEK_CUR);

            for(int j = 0; j<sizeof(ptr->shopAdress); j++){//робиться для видалення симвоу кінця рядку
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

            if(front == NULL){//Якщо це перший елемент
                front = ptr;
                rear = ptr;
                front -> next = NULL;
            }
            else{//Якщо не перший
                rear -> next = ptr;
                rear = ptr;
                rear -> next = NULL;
            }
        }
    }
}
