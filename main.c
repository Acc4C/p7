#include <stdio.h>
#include "myio.h"
#include "tree.h"

int main(){
    int choice, err, value;
    if (getInt(&value, "Введите значение корня дерева: ") == -1){ return 0; }
    Tree* root = createTree(value);
    if (root == NULL){
        printError(1);
        return 0;
    }
    while (1){
        printf("Выберите действие:\n  1. Добавить новый узел\n  2. Вывести таблицу\n  3. Удалить узел\n  4. Посчитать количество вершин\n  5. Выход\n");
        if (getInt(&choice, "Выберите число: ") == -1){
            freeTree(root);
            return 0;
        }
        switch (choice){
            case 1:
                if (getInt(&value, "Введите значение: ") == -1){
                    freeTree(root);
                    return 0;
                }
                err = addNode(root, value);
                printError(err);
                if (err == 1){
                    freeTree(root);
                    return 0;
                }
                if (!err){ printf("Узел со значением %d добавлен\n", value); }
                break;
            case 2:
                printTree(root, 0);
                break;
            case 3:
                if (getInt(&value, "Введите значение: ") == -1){
                    freeTree(root);
                    return 0;
                }
                err = removeNode(&root, value);
                printError(err);
                if (!err){ printf("Узел со значением %d удалён\n", value); }
                break;
            case 4:
                printf("В дереве %d узла(ов)\n", nodesCount(root));
                break;
            case 5:
                freeTree(root);
                return 0;
            default:
                printf("Некорректный ввод\n");
        }
        printf("\n");
    }
    return 0;
}
