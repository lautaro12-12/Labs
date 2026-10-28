
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
// Precondition: The input file must contain temperature data.
// Precondicion: El archivo debe contener datos de temperatura.

// Postcondition: The program displays a chart for valid temperatures.
// Poscondicion: El programa muestra un grafico de temperaturas validas.
int main()
{
    // Open the input file / Abrir el archivo de entrada
    ifstream inputFile("C:\\Users\\lauta\\source\\repos\\Lab4 computer science\\x64\\Debug\\temperatures.txt");

    // Check if the file opened / Verificar si se abrió
    if (!inputFile)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    int temperature;

    // Print the chart heading / Mostrar el titulo del grafico
    cout << "Temperature Bar Chart" << endl;
    cout << "Scale: Each * represents a 3-degree interval." << endl;
    cout << "---------------------------------------------" << endl;

    // Read temperatures from the file / Leer temperaturas del archivo
    while (inputFile >> temperature)
    {
        // Check the valid range / Verificar el rango permitido
        if (temperature < -30 || temperature > 120)
        {
            cout << "Invalid temperature: " << temperature << endl;
            continue;
        }

        // Print the temperature / Mostrar la temperatura
        cout << setw(4) << temperature << ": ";

        // Calculate the number of stars / Calcular la cantidad de estrellas
        int stars = (temperature + 30) / 3;

        // Print the bar / Mostrar la barra
        for (int i = 0; i < stars; i++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // Check for invalid input / Verificar datos incorrectos
    if (!inputFile.eof())
    {
        cout << "Invalid data found in the file." << endl;
    } 

    // Close the file / Cerrar el archivo
    inputFile.close();

    return 0;
}
