#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main()
{
    //The variables
    int students, i, sum, gradeA;
    double average;
    char again = 'y', fileans;
    string name;

    //while for again input
    while(again == 'y' || again == 'Y')
    {
        //Prompting the user to enter the number of students
        cout << string(50, '\n');
        cout << "Enter no. of students : ";
        cin >> students;

        //Declaring an array for marks
        int marks[students];

        //Prompting the user to enter the marks for each students
        for(i = 1; i <= students; i++)
        {
            cout << "Enter marks of student " << i << " : ";
            cin >> marks[i];
        }

        //Displaying the marks for each student for reference
        for(i = 1; i <= students; i++)
        {
            cout << "student " << i << ": " << marks[i] << endl;
        }
        /*


        LINE BREAK


        */
        //To find the average from all the marks
        sum = 0;
        for(i = 1; i <= students; i++)
        {
            sum = sum + marks[i];
        }
        average = sum / students;
        cout << "\nThe average mark is : " << average << endl;
        /*


        LINE BREAK


        */
        //To find the no. of Grade A from the students marks
        gradeA=0;
        for(i = 1; i <= students; i++)
        {
            if(marks[i] >= 80)
                gradeA++;
        }
        cout << "The no. of Grade A achieved is : " << gradeA << endl;
        /*


        LINE BREAK


        */
        //Option if they want a Txt file created
        cout << "\nDo you want to create a Txt file? (y/n) :";
        cin >> fileans;

        //Making a txt file for the results if yes was said
        if(fileans == 'y' || fileans == 'Y')
        {
            cout << "Please name this file : ";
            cin >> name;
            name += string(".txt");
            ofstream MyFile(name);
            for(i = 1; i <= students; i++)
            {
                MyFile << "Student " << i << ": " << marks[i] << endl;
            }
            MyFile << "Average : " << average << endl;
            MyFile << "No. of As : " << gradeA << endl;
            MyFile.close();
            cout << "\nTxt file was created..." << endl;
            cout << "File can be found in your exe folder" << endl;
        }
        /*


        LINE BREAK


        */
        //Prompting the user if he would like to use the program again
        cout << "\nWould you like to use the program again? (y/n) : ";
        cin >> again;
    }

    //Simple Thank you message
    cout << string(50, '\n');
    cout << "======================" << endl;
    cout << "      Thank You!      " << endl;
    cout << "======================" << endl;
    Sleep(1000);

    return 0;
}
