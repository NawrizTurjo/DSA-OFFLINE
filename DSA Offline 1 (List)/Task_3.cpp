#include <iostream>
#include <cstring>
#include "Arr.cpp"
#include "LL.cpp"
#define List Llist

void read_string(List &list, int max_car)
{
    char *str = new char[100];
    char *temp = new char[10];
    int i = 0;
    int size = 0;
    gets(str);
    // cout << str << endl;
    while (str[i] != '\0')
    {
        int j = 0;
        while (str[i] != ' ' && str[i] != '\0')
        {
            temp[j] = str[i];
            i++;
            j++;
        }
        temp[j] = '\0';
        int last = atoi(temp);
        // cout << last << endl;
        if (size == 0)
            list.insert(last);
        else
        {
            list.moveToEnd();
            int remember = list.getValue();
            list.insert(last);
            list.insert(remember);
            list.moveToEnd();
            list.remove();
        }
        size++;
        if (size > max_car)
        {
            // cout << "No more car can be parked" << endl;
            list.moveToStart();
            break;
        }
        if (str[i] != '\0')
            i++;
    }
    // cout << endl;
    delete[] str;
    delete[] temp;
    list.moveToStart();
}
void PRINT(List &list)
{
    if (list.length() == 1)
    {
        cout << " ";
    }
    list.moveToStart();
    list.next();
    for (int i = 1; i < list.length(); i++)
    {
        cout << list.getValue() << " ";
        list.next();
    }
}
int main()
{
    int num_garage, max_car, num_cars;
    cin >> num_cars;
    // cout << num_cars << endl;
    cin >> num_garage;
    // cout << num_garage << endl;
    cin >> max_car;
    cin.ignore();
    // cout << max_car << endl;
    int max_capacity = num_garage * max_car;
    if (num_cars > max_capacity)
    {
        cout << "Max Capacity Exceeded" << endl;
        return 1;
    }
    List *list = new List[num_garage];
    // int total_cars = 0;
    for (int i = 0; i < num_garage; i++)
    {
        // cout << "inner loop " << i << endl;
        read_string(list[i], max_car);
    }
    // sort lists
    for (int i = 0; i < num_garage - 1; i++)
    {
        for (int j = i; j < num_garage; j++)
        {
            if (list[i].getValue() > list[j].getValue())
            {
                List *temp = new List;
                *temp = list[i];
                list[i] = list[j];
                list[j] = *temp;
            }
        }
    }
    for (int i = 0; i < num_garage; i++)
    {
        PRINT(list[i]);
        cout << endl;
    }
    // cin.ignore();
    char *line = new char[100];
    while (1)
    {
        gets(line);
        if (strncmp(line, "req", 3) == 0)
        {
            int flag = 0;
            for (int i = 0; i < num_garage; i++)
            {
                if (list[i].length() > 1)
                {
                    list[i].moveToStart();
                    list[i].next();
                    int min = list[i].getValue();
                    int index = 1;
                    for (int j = 1; j < list[i].length(); j++)
                    {
                        if (list[i].getValue() < min)
                        {
                            min = list[i].getValue();
                            index = list[i].currPos();
                        }
                        list[i].next();
                    }
                    list[i].moveToPos(index);
                    list[i].remove();
                    list[i].moveToStart();
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                for (int i = 0; i < num_garage; i++)
                {
                    PRINT(list[i]);
                    cout << endl;
                }
            }
            else if (flag != 1)
                cout << "Not available" << endl;
        }
        else if (strncmp(line, "ret", 3) == 0)
        {
            char *temp = new char[10];
            int i = 4, j = 0;
            while (line[i] != '\0')
            {
                temp[j] = line[i];
                i++;
                j++;
            }
            temp[j] = '\0';
            int num = atoi(temp);
            delete[] temp;
            // cout << num << endl;
            //  do ret
            int flag = 0;
            for (int k = num_garage - 1; k >= 0; k--)
            {
                if (list[k].length() <= max_car)
                {
                    if (list[k].length() > 1)
                    {
                        list[k].moveToStart();
                        list[k].next();
                        int max = list[k].getValue();
                        int index = 1;
                        for (int j = 1; j < list[k].length(); j++)
                        {
                            if (list[k].getValue() > max)
                            {
                                max = list[k].getValue();
                                index = list[k].currPos();
                            }
                            list[k].next();
                        }
                        if (index < list[k].length() - 1)
                        {
                            list[k].moveToPos(index + 1);
                            list[k].insert(num);
                            list[k].moveToStart();
                            flag = 1;
                            break;
                        }
                        else if (index == list[k].length() - 1)
                        {
                            list[k].moveToEnd();
                            int remember = list[k].getValue();
                            list[k].insert(num);
                            list[k].next();
                            list[k].remove();
                            list[k].insert(remember);
                            list[k].moveToStart();
                            flag = 1;
                            break;
                        }
                    }
                    else if (list[k].length() == 1)
                    {
                        int remember = list[k].getValue();
                        list[k].insert(num);
                        list[k].next();
                        list[k].remove();
                        list[k].insert(remember);
                        list[k].moveToStart();
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1)
            {
                for (int i = 0; i < num_garage; i++)
                {
                    PRINT(list[i]);
                    cout << endl;
                }
            }
            else if (flag != 1)
                cout << "Max Exceeded" << endl;
        }
        else if (strcmp(line, "end") == 0)
        {
            break;
        }
    }
    delete[] line;
    delete[] list;

    return 0;
}
