#include <iostream>
#include <chrono>
#include <cstdlib> // Para srand y rand
#include <ctime>   // Para time
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <random>

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList() : head(new Node(-1)) {}

    void insert(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head->next;
        if (head->next)
        {
            head->next->prev = newNode;
        }
        newNode->prev = head;
        head->next = newNode;
    }

    void display()
    {
        Node *current = head->next;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node *getHead()
    {
        return head;
    }
};

struct Data
{
    int score;           // La calificación numérica
    std::string payload; // Información adicional asociada a la calificación (datos simulados)

    Data(int v, std::string p) : score(v), payload(std::move(p)) {}
};

bool compareScores(Data &a, Data &b)
{
    return a.score < b.score;
}

std::vector<int> extractScores(const std::vector<Data> &data)
{
    std::vector<int> scores;
    scores.reserve(data.size());
    for (const auto &d : data)
    {
        scores.push_back(d.score);
    }
    return scores;
}

std::vector<Data> reorderData(const std::vector<Data> &data, const std::vector<int> &sortedScores)
{
    std::vector<Data> sortedData;
    sortedData.reserve(data.size());

    for (int score : sortedScores)
    {
        auto it = std::find_if(data.begin(), data.end(),
                               [score](const Data &d)
                               { return d.score == score; });
        if (it != data.end())
        {
            sortedData.push_back(*it);
        }
    }

    return sortedData;
}

// Insertion Sort
int insertionSort(std::vector<int> &array, int length);
int insertionSortOptimized(std::vector<int> &array, int length);
int binarySearch(std::vector<int> &array, int key, int low, int high);
int insertionSortDesc(std::vector<int> &array, int length);
int insertionSortOptimizedDesc(std::vector<int> &array, int length);
int binarySearchDesc(std::vector<int> &array, int key, int low, int high);
// Node *binarySearch(DoublyLinkedList &list, int key);

// Bubble Sort
int bubbleSort(std::vector<int> &array, int length);
int bubbleSortEarlyTermination(std::vector<int> &array, int length);
int cocktailShakerSort(std::vector<int> &array, int size);
int bubbleSortDesc(std::vector<int> &array, int length);
int bubbleSortEarlyTerminationDesc(std::vector<int> &array, int length);
int cocktailShakerSortDesc(std::vector<int> &array, int size);

// Selection Sort
int selectionSort(std::vector<int> &array, int length);
int bidirectionalSelectionSort(std::vector<int> &array, int length);
int selectionSortDesc(std::vector<int> &array, int length);
int bidirectionalSelectionSortDesc(std::vector<int> &array, int length);

// Merge Sort
void mergeSort(std::vector<int> &array, int left, int right);
void merge(std::vector<int> &array, int left, int middle, int right);
void mergeSortDesc(std::vector<int> &array, int left, int right);
void mergeDesc(std::vector<int> &array, int left, int middle, int right);

// Quick Sort
void quickSort(std::vector<int> &array, int low, int high);
void quickSortRandom(std::vector<int> &array, int low, int high);
int partition(std::vector<int> &array, int low, int high);
int randomPivotIndex(int low, int high);
void quickSortDesc(std::vector<int> &array, int low, int high);
void quickSortRandomDesc(std::vector<int> &array, int low, int high);
int partitionDesc(std::vector<int> &array, int low, int high);

int main()
{

    // Insertion Sort
    int totalDurationIS = 0;
    int totalDurationISO = 0;
    int totalDurationISOL = 0;
    int totalDurationISOL2 = 0;
    int totalDurationISS = 0;
    int totalDurationISS2 = 0;
    int totalDurationCSS = 0;

    // Bubble Sort
    int totalDurationBS = 0;
    int totalDurationBSET = 0;

    // Selection sort
    int totalDurationSS = 0;
    int totalDurationSS2 = 0;

    // Merge sort
    int totalDurationMS = 0;

    // Quick sort
    int totalDurationQS = 0;
    int totalDurationQSR = 0;

    // Introsort
    int totalDurationIntroSort = 0;

    // c++ Stable sort
    int totalDurationStableSort = 0;

    // Haremos 10000 pruebas con un arreglo de 200 elementos
    int numTests = 50000;
    int size = 200;

    std::mt19937 rng(time(0));

    // Distribuciones
    std::uniform_int_distribution<int> score_distribution(1, 100);
    std::uniform_int_distribution<int> index_distribution(0, size - 1);

    for (int i = 0; i < numTests; i++)
    {
        std::vector<Data> data;

        /*for (int i = 0; i < size; i++)
        {
            std::ostringstream ss;
            ss << "item: " << (i + 1);
            int score = score_distribution(rng);
            data.emplace_back(score, ss.str());
        }*/
        short counter = 100;
        for (int i = 0; i < size; i++)
        {   
            if (i % 2 == 0){
                counter--;
            }
            std::ostringstream ss;
            ss << "item: " << (i + 1);
            int score = 100 - counter;
            data.emplace_back(score, ss.str());
        }

        int numSwaps = size / 10;
         for (int i = 0; i < numSwaps; i++) {
             int idx1 = index_distribution(rng);
             int idx2 = index_distribution(rng);
             std::swap(data[idx1], data[idx2]);
         }

        std::vector<Data> tempData = data;
        std::vector<int> scores = extractScores(tempData);

        totalDurationIS += insertionSortDesc(scores, scores.size());

        tempData = data;
        scores = extractScores(tempData);
        totalDurationISO += insertionSortOptimizedDesc(scores, scores.size());

        //Mostrar el resultado
        /*for (int i = 0; i < scores.size(); i++)
        {
            std::cout << scores[i] << " ";
        } 
        std::cout << std::endl;*/


        tempData = data;
        scores = extractScores(tempData);

        totalDurationBS += bubbleSortDesc(scores, scores.size());

        tempData = data;
        scores = extractScores(tempData);

        totalDurationBSET += bubbleSortEarlyTerminationDesc(scores, scores.size());

        tempData = data;
        scores = extractScores(tempData);

        totalDurationCSS += cocktailShakerSortDesc(scores, scores.size());

        tempData = data;
        scores = extractScores(tempData);

        totalDurationSS += selectionSortDesc(scores, scores.size());

        /*tempData = data;
        scores = extractScores(tempData);

        totalDurationSS2 += bidirectionalSelectionSort(scores, scores.size());*/

        tempData = data;
        scores = extractScores(tempData);

        auto start = std::chrono::high_resolution_clock::now();
        mergeSortDesc(scores, 0, scores.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        totalDurationMS += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        tempData = data;
        scores = extractScores(tempData);

        start = std::chrono::high_resolution_clock::now();
        quickSortDesc(scores, 0, scores.size() - 1);
        end = std::chrono::high_resolution_clock::now();
        totalDurationQS += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        tempData = data;
        scores = extractScores(tempData);

        start = std::chrono::high_resolution_clock::now();
        quickSortRandomDesc(scores, 0, scores.size() - 1);
        end = std::chrono::high_resolution_clock::now();
        totalDurationQSR += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // Ahora utilizamos las librerías de C++ para ordenar el arreglo
        tempData = data;
        scores = extractScores(tempData);
        start = std::chrono::high_resolution_clock::now();
        std::sort(scores.begin(), scores.end(), [](int a, int b)
                  { return a > b; });
        end = std::chrono::high_resolution_clock::now();

        totalDurationIntroSort += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        tempData = data;
        scores = extractScores(tempData);
        start = std::chrono::high_resolution_clock::now();
        std::stable_sort(scores.begin(), scores.end(), [](int a, int b)
                         { return a > b; });
        end = std::chrono::high_resolution_clock::now();

        totalDurationStableSort += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    std::cout << "\n\n Average Insertion Sort time execution: " << totalDurationIS / numTests << " microseconds" << std::endl;
    std::cout << "\n\n Average Insertion Sort Optimized time execution: " << totalDurationISO / numTests << " microseconds" << std::endl;
    std::cout << "\n\n Average Bubble Sort time execution: " << totalDurationBS / numTests << " microseconds" << std::endl;
    std::cout << "\n\n Average Bubble Sort Early Termination time execution: " << totalDurationBSET / numTests << " microseconds" << std::endl;
    std::cout << "\n\n Average Cocktail Shaker Sort time execution: " << totalDurationCSS / numTests << " microseconds" << std::endl;
    std::cout << "\n\n Average Selection Sort time execution: " << totalDurationSS / numTests << " microseconds" << std::endl;
    // std::cout << "\n\n Average Bidirectional Selection Sort time execution: " << totalDurationSS2 / numTests << " microseconds" << std::endl;
    std::cout << "\n\n Average Merge Sort time execution: " << totalDurationMS / numTests << " microseconds" << std::endl;
    std::cout << "\n\n Average Quick Sort time execution: " << totalDurationQS / numTests << " microseconds" << std::endl;
    std::cout << "\n\n Average Quick Sort Random time execution: " << totalDurationQSR / numTests << " microseconds" << std::endl;
    std::cout << "\n\n Average Intro Sort time execution: " << totalDurationIntroSort / numTests << " microseconds" << std::endl;
    std::cout << "\n\n Average Stable Sort time execution: " << totalDurationStableSort / numTests << " microseconds" << std::endl;

    return 0;
}

int binarySearch(std::vector<int> &array, int key, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == key)
            return mid;
        else if (array[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Método de búsqueda binaria si el orden es descendente
int binarySearchDesc(std::vector<int> &array, int key, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == key)
            return mid;
        else if (array[mid] > key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int insertionSortOptimized(std::vector<int> &array, int length)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 1; i < length; i++)
    {
        int key = array[i];
        int insertPosition = binarySearch(array, key, 0, i - 1);

        for (int j = i - 1; j >= insertPosition; j--)
        {
            array[j + 1] = array[j];
        }
        array[insertPosition] = key;
    }

    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// InsertionSortOptimized para ordenar descendentemente
int insertionSortOptimizedDesc(std::vector<int> &array, int length)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 1; i < length; i++)
    {
        int key = array[i];
        int insertPosition = binarySearchDesc(array, key, 0, i - 1);

        for (int j = i - 1; j >= insertPosition; j--)
        {
            array[j + 1] = array[j];
        }
        array[insertPosition] = key;
    }

    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int insertionSort(std::vector<int> &array, int length)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < length; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// InsertionSort descendente
int insertionSortDesc(std::vector<int> &array, int length)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < length; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] < key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int bubbleSort(std::vector<int> &array, int length)
{
    auto start = std::chrono::high_resolution_clock::now();
    int j;
    for (int i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// BubbleSort descendente
int bubbleSortDesc(std::vector<int> &array, int length)
{
    auto start = std::chrono::high_resolution_clock::now();
    int j;
    for (int i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int bubbleSortEarlyTermination(std::vector<int> &array, int length)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < length - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// BubbleSortEarlyTermination descendente
int bubbleSortEarlyTerminationDesc(std::vector<int> &array, int length)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < length - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (array[j] < array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int cocktailShakerSort(std::vector<int> &array, int size)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size / 2; i++)
    {
        bool swapped = false;
        for (int j = i; j < size - i - 1; j++)
        { // one way
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                swapped = true;
            }
        }
        for (int j = size - 2 - i; j > i; j--)
        { // and back
            if (array[j] < array[j - 1])
            {
                int tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// CocktailShakerSort descendente
int cocktailShakerSortDesc(std::vector<int> &array, int size)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size / 2; i++)
    {
        bool swapped = false;
        for (int j = i; j < size - i - 1; j++)
        { // one way
            if (array[j] < array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                swapped = true;
            }
        }
        for (int j = size - 2 - i; j > i; j--)
        { // and back
            if (array[j] > array[j - 1])
            {
                int tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int selectionSort(std::vector<int> &array, int length)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < length - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// SelectionSort descendente
int selectionSortDesc(std::vector<int> &array, int length)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < length - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[j] > array[maxIndex])
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            int temp = array[i];
            array[i] = array[maxIndex];
            array[maxIndex] = temp;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

void merge(std::vector<int> &array, int left, int middle, int right)
{
    // Calcula las longitudes de los dos subarreglos a fusionar
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Crea dos arreglos temporales para almacenar los subarreglos izquierdo y derecho
    int *leftArray = new int[n1];
    int *rightArray = new int[n2];

    // Copia los elementos del subarreglo izquierdo al arreglo izquierdo
    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = array[left + i];
    }

    // Copia los elementos del subarreglo derecho al arreglo derecho
    for (int i = 0; i < n2; i++)
    {
        rightArray[i] = array[middle + 1 + i];
    }

    // Inicializa índices para recorrer los arreglos temporales y el arreglo original
    int i = 0, j = 0, k = left;

    // Comienza la fusión de los dos arreglos temporales en el arreglo original
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copia cualquier elemento restante del subarreglo izquierdo al arreglo original
    while (i < n1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copia cualquier elemento restante del subarreglo derecho al arreglo original
    while (j < n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    // Libera la memoria asignada para los arreglos temporales
    delete[] leftArray;
    delete[] rightArray;
}

// MergeSort descendente
void mergeDesc(std::vector<int> &array, int left, int middle, int right)
{
    // Calcula las longitudes de los dos subarreglos a fusionar
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Crea dos arreglos temporales para almacenar los subarreglos izquierdo y derecho
    int *leftArray = new int[n1];
    int *rightArray = new int[n2];

    // Copia los elementos del subarreglo izquierdo al arreglo izquierdo
    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = array[left + i];
    }

    // Copia los elementos del subarreglo derecho al arreglo derecho
    for (int i = 0; i < n2; i++)
    {
        rightArray[i] = array[middle + 1 + i];
    }

    // Inicializa índices para recorrer los arreglos temporales y el arreglo original
    int i = 0, j = 0, k = left;

    // Comienza la fusión de los dos arreglos temporales en el arreglo original
    while (i < n1 && j < n2)
    {
        if (leftArray[i] >= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copia cualquier elemento restante del subarreglo izquierdo al arreglo original
    while (i < n1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copia cualquier elemento restante del subarreglo derecho al arreglo original
    while (j < n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    // Libera la memoria asignada para los arreglos temporales
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(std::vector<int> &array, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}

// MergeSort descendente
void mergeSortDesc(std::vector<int> &array, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSortDesc(array, left, middle);
        mergeSortDesc(array, middle + 1, right);

        mergeDesc(array, left, middle, right);
    }
}

void quickSort(std::vector<int> &array, int low, int high)
{
    if (low < high)
    {
        // Encuentra el índice del pivote tal que los elementos menores a pivote estén a la izquierda
        int pivotIndex = partition(array, low, high);

        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

int partition(std::vector<int> &array, int low, int high)
{
    // Seleccionamos el pivote como el último elemento del arreglo
    int pivot = array[high];

    int i = (low - 1); // Índice del elemento más pequeño

    for (int j = low; j <= high - 1; j++)
    {
        // Si el elemento actual es menor o igual al pivote
        if (array[j] <= pivot)
        {
            i++; // Incrementa el índice del elemento más pequeño
            // Intercambio de array[i] y array[j]
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    // intercambio manual de array[i + 1] y array[high] (o pivote)
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return (i + 1);
}

// QuickSort descendente
int partitionDesc(std::vector<int> &array, int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // Cambio clave para orden descendente
        if (array[j] > pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return (i + 1);
}

void quickSortDesc(std::vector<int> &array, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionDesc(array, low, high);

        quickSortDesc(array, low, pivotIndex - 1);
        quickSortDesc(array, pivotIndex + 1, high);
    }
}

void quickSortRandom(std::vector<int> &array, int low, int high)
{
    if (low < high)
    {
        // Selecciona un índice de pivote aleatorio y lo intercambia con el último elemento
        int pivotIndex = randomPivotIndex(low, high);

        int temp = array[pivotIndex];
        array[pivotIndex] = array[high];
        array[high] = temp;

        pivotIndex = partition(array, low, high);

        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

// quickSortRandom descendente
void quickSortRandomDesc(std::vector<int> &array, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = randomPivotIndex(low, high);

        int temp = array[pivotIndex];
        array[pivotIndex] = array[high];
        array[high] = temp;

        pivotIndex = partitionDesc(array, low, high);

        quickSortDesc(array, low, pivotIndex - 1);
        quickSortDesc(array, pivotIndex + 1, high);
    }
}

int randomPivotIndex(int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    return random;
}