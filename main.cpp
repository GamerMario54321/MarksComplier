#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //The variables
    int students, i, o, sum, gradeA[o], subject;
    double average[o];
    char again = 'y', fileans;
    string name;

    //while for again input
    while(again == 'y' || again == 'Y')
    {
        //Prompting the user to enter the number of students
        cout << string(50, '\n');
        cout << "Enter no. of students : ";
        cin >> students;

        //Prompting the user to enter the number of subjectd
        cout << "Enter no. of subjects : ";
        cin >> subject;

        //Declaring an array for marks
        int marks[students][subject];
        /*


        LINE BREAK


        */
        //Prompting the user to enter the marks for each students and subject
        for(o = 1; o <= subject; o++)
        {
            cout << string(50, '\n');
            cout << "Entering for subject " << o << "\n" << endl;
            for(i = 1; i <= students; i++)
            {
                cout << "Enter marks of student " << i << " for subject " << o <<  " : ";
                cin >> marks[i][o];
            }
            cout << string(50, '\n');
        }
        /*


        LINE BREAK


        */
        for(o = 1; o <= subject; o++)
        {
            //Displaying the marks for each student for reference
            cout << "Subject " << o << endl;
            for(i = 1; i <= students; i++)
            {
                cout << "student " << i << ": " << marks[i][o] << endl;
            }
            cout << endl;
            /*


            LINE BREAK


            */
            //To find the average from all the marks
            sum = 0;
            for(i = 1; i <= students; i++)
            {
                sum = sum + marks[i][o];
            }
            average[o] = sum / students;
            cout << "The average mark is for subject " << o << " : " << average[o] << endl;
            /*


            LINE BREAK


            */
            //To find the no. of Grade A from the students marks
            gradeA[o]=0;
            for(i = 1; i <= students; i++)
            {
                if(marks[i][o] >= 80)
                gradeA[o]++;
            }
            cout << "The no. of Grade A achieved for subject " << o << " : " << gradeA[o] << endl << endl;
            system("pause");
            cout << string(50, '\n');
        }
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
            MyFile << "---------------------" << endl;
            for(o = 1; o <= subject; o++)
            {
                MyFile << "Subject " << o << endl << endl;
                for(i = 1; i <= students; i++)
                {
                    MyFile << "Student " << i << ": " << marks[i][o] << endl;
                }
                MyFile << "\nAverage : " << average[o] << endl;
                MyFile << "No. of As : " << gradeA[o] << endl;
                MyFile << "---------------------" << endl;
            }
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
    cout << "======================" << endl << endl;
    system("pause");

    return 0;
}
