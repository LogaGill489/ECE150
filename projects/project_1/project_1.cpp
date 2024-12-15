#include <iostream>
#include <cmath>

// variables to track grades and what their out of
int M1, M2, M3, M4, M5, M6, M7, currentM;
float G1, G2, G3, G4, G5, G6, G7, currentG;
float A1, A2, A3, A4, A5, A6, A7, currentA;
float final, input;

void setCurrents(int i)
{
    switch (i)
    {
    case 0:
        currentM = M1;
        currentG = G1;
        currentA = A1;
        break;
    case 1:
        currentM = M2;
        currentG = G2;
        currentA = A2;
        break;
    case 2:
        currentM = M3;
        currentG = G3;
        currentA = A3;
        break;
    case 3:
        currentM = M4;
        currentG = G4;
        currentA = A4;
        break;
    case 4:
        currentM = M5;
        currentG = G5;
        currentA = A5;
        break;
    case 5:
        currentM = M6;
        currentG = G6;
        currentA = A6;
        break;
    case 6:
        currentM = M7;
        currentG = G7;
        currentA = A7;
        break;
    }
}

void setAverages(int i)
{
    switch (i)
    {
    case 0:
        A1 = currentA;
        break;
    case 1:
        A2 = currentA;
        break;
    case 2:
        A3 = currentA;
        break;
    case 3:
        A4 = currentA;
        break;
    case 4:
        A5 = currentA;
        break;
    case 5:
        A6 = currentA;
        break;
    case 6:
        A7 = currentA;
        break;
    }
}

void maxEnter(int i)
{
    do // waits until a number greater than 0 is input, used for totals
    {
        // outputs proper message based on the information being taken in
        if (i == 0)
        {
            std::cout << "Enter Max Score For Final: ";
        }
        else if (i == 1)
        {
            std::cout << "Enter Max Score For The Midterm: ";
        }
        else
        {
            std::cout << "Enter Max Score For Project " << i - 1 << " : ";
        }

        // takes in total and confirms that it is above 0, otherwise repeating until this is true
        std::cin >> input;
        switch (i)
        {
        case 0:
            M1 = input;
            if (M1 <= 0 || M1 != input)
            {
                M1 = -1;
                std::cout << "Please Enter An Integer Above 0." << std::endl;
            }
            break;
        case 1:
            M2 = input;
            if (M2 <= 0 || M2 != input)
            {
                M2 = -1;
                std::cout << "Please Enter An Integer Above 0." << std::endl;
            }
            break;
        case 2:
            M3 = input;
            if (M3 <= 0 || M3 != input)
            {
                M3 = -1;
                std::cout << "Please Enter An Integer Above 0." << std::endl;
            }
            break;
        case 3:
            M4 = input;
            if (M4 <= 0 || M4 != input)
            {
                M4 = -1;
                std::cout << "Please Enter An Integer Above 0." << std::endl;
            }
            break;
        case 4:
            M5 = input;
            if (M5 <= 0 || M5 != input)
            {
                M5 = -1;
                std::cout << "Please Enter An Integer Above 0." << std::endl;
            }
            break;
        case 5:
            M6 = input;
            if (M6 <= 0 || M6 != input)
            {
                M6 = -1;
                std::cout << "Please Enter An Integer Above 0." << std::endl;
            }
            break;
        case 6:
            M7 = input;
            if (M7 <= 0 || M7 != input)
            {
                M7 = -1;
                std::cout << "Please Enter An Integer Above 0." << std::endl;
            }
            break;
        }
        setCurrents(i);
    } while (currentM <= 0);
}

void gradeEnter(int i)
{
    do // waits until a number is put in range, used for calcing the students score
    {
        currentG = -1;
        // outputs proper message based on the information being taken in
        if (i == 0)
        {
            std::cout << "Enter Your Final Score: ";
        }
        else if (i == 1)
        {
            std::cout << "Enter Your Midterm Score: ";
        }
        else
        {
            std::cout << "Enter Your Score For Project " << i - 1 << " : ";
        }

        // intakes students grade and displays an error if it is out of range
        switch (i)
        {
        case 0:
            std::cin >> G1;
            if (G1 < 0 || G1 > M1) // checks if the input is invalid in any way
                std::cout << "Out of Range.  Please Enter A Valid Number." << std::endl;
            break;
        case 1:
            std::cin >> G2;
            if (G2 < 0 || G2 > M2) // checks if the input is invalid in any way
                std::cout << "Out of Range.  Please Enter A Valid Number." << std::endl;
            break;
        case 2:
            std::cin >> G3;
            if (G3 < 0 || G3 > M3) // checks if the input is invalid in any way
                std::cout << "Out of Range.  Please Enter A Valid Number." << std::endl;
            break;
        case 3:
            std::cin >> G4;
            if (G4 < 0 || G4 > M4) // checks if the input is invalid in any way
                std::cout << "Out of Range.  Please Enter A Valid Number." << std::endl;
            break;
        case 4:
            std::cin >> G5;
            if (G5 < 0 || G5 > M5) // checks if the input is invalid in any way
                std::cout << "Out of Range.  Please Enter A Valid Number." << std::endl;
            break;
        case 5:
            std::cin >> G6;
            if (G6 < 0 || G6 > M6) // checks if the input is invalid in any way
                std::cout << "Out of Range.  Please Enter A Valid Number." << std::endl;
            break;
        case 6:
            std::cin >> G7;
            if (G7 < 0 || G7 > M7) // checks if the input is invalid in any way
                std::cout << "Out of Range.  Please Enter A Valid Number." << std::endl;
            break;
        }
        setCurrents(i);
    } while (currentG < 0 || currentG > currentM);
}

int main()
{
    while (true)
    {
        // runs for each thing worth marks
        for (int i = 0; i < 7; i++)
        {
            maxEnter(i);
            gradeEnter(i);
        }
        // calculates averages
        for (int i = 0; i < 7; i++)
        {
            setCurrents(i); // gets M(i) and G(i)
            currentA = 100 * (currentG / currentM);
            setAverages(i); // stores A(i)
        }

        // weighs in favour of the final exam's mark
        for (int i = 1; i < 7; i++)
        {
            setCurrents(i);
            if (currentA < A1)
            {
                currentA = A1;
                setAverages(i);
            }
        }

        // test average weighed calculation
        float testAverage = (A1 * 0.75) + (A2 / 4);

        // project average calculation
        float projectAverage;
        for (int i = 2; i < 7; i++)
        {
            setCurrents(i);
            projectAverage += currentA;
        }
        projectAverage /= 5;

        // case 1 of final grade
        if (testAverage <= 40)
        {
            final = testAverage;
        }
        else if (testAverage >= 60)
        {
            final = (2 * testAverage) / 3 + projectAverage / 3;
        }
        else
        {
            final = (projectAverage * (testAverage - 40) / 60) + (testAverage * (1 - ((testAverage - 40) / 60)));
        }

        // rounds final answer to an int solution
        final = std::round(final + 1e-12);

        // outputs final score
        std::cout << "Your Course Mark Is " << final << "%.";
    }
}