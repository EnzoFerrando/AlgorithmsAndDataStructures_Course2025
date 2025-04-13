#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

/**
 * @brief Nodo de lista simplemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
struct ListNode
{
    TData data;
    ListNode* next;

    explicit ListNode(const TData& value)
        : data(value)
        , next(nullptr)
    {
    }
};

/**
 * @brief Implementación de una lista simplemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
class LinkedList
{
private:
    ListNode<TData>* head;

public:
    LinkedList()
        : head(nullptr)
    {
    }

    ~LinkedList()
    {
        //throw std::runtime_error("Not implemented yet");
       while (head != nullptr){
        auto* temporalNode = head;
        head = head->next;
        delete temporalNode;
        }
    }

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    void push_front(const TData& value)
    {
        //throw std::runtime_error("Not implemented yet");
        auto* newNode = new ListNode<TData>(value);
        newNode->next = head;
        head = newNode;
    }

    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
    void remove_at(size_t position)
    {
        //throw std::runtime_error("Not implemented yet");
        auto* temporalNode = head;
        auto* leftNode = head;
        size_t count = 0;
        if (head->next == nullptr) //comprueba que no es una lista vacia
            return;
        if(position == 0){ //si se quiere remover el primer elemento de la lista
           head = head->next;
           delete temporalNode;
           return; }
        while (count<position)
        {
            leftNode = temporalNode;
            if(temporalNode->next == nullptr) //comprueba no estar en el ultimo nodo antes de avanzar
              return;
            temporalNode = temporalNode->next;
            count++;
        }
        leftNode->next = temporalNode->next;
        delete temporalNode;
    }

    /**
    * @brief Crea una lista nueva de n elementos a partir de una posición dada
    *
    */
    ListNode<TData>* take(size_t startPosition, size_t nElements)
    {
        //throw std::runtime_error("Not implemented yet");
        if (head->next == nullptr) //comprobar que no es una lista vacia
        return nullptr;
        auto* temporalNode = head; //crea un nodo inicializado en la primera posicion
        size_t count = 0;
        while(count<startPosition){
         if(temporalNode->next == nullptr) //comprobar que la posicion de inicio no este fuera de rango
         return nullptr;
         temporalNode = temporalNode->next;
         count++;
         }
        auto* newList = new LinkedList<TData>(); //inicializa la nueva lista
        auto* newHead = temporalNode; //la nueva cabeza es la posicion de inicio a copiar
        auto* leftNode = temporalNode; //crea un nodo anteriror para ir enlazando la nueva lista
        newList->head = newHead; //asigna la nueva cabeza a la nueva lista
        temporalNode=temporalNode->next; //crea la primera copia, avanza un lugar
        count = 1;
        while (count<nElements)
        {
            auto* newNode = temporalNode; //crea cada nuevo nodo
            leftNode->next = newNode; //enlaza el anterior nuevo nodo con el proximo
            leftNode = newNode; //avanza una posicion
            temporalNode = temporalNode->next; //avanza una posicion
            count++;
        }
        return newHead; //retorna la cabeza de la nueva lista
    }

    /**
     * @brief Imprime todos los elementos de la lista
     */
    void print() const
    {
        ListNode<TData>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

/**
 * @brief Nodo de lista doblemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
struct DoublyListNode
{
    TData data;
    DoublyListNode* next;
    DoublyListNode* prev;

    explicit DoublyListNode(const TData& value)
        : data(value)
        , next(nullptr)
        , prev(nullptr)
    {
    }
};

/**
 * @brief Implementación de una lista doblemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
class DoublyLinkedList
{
private:
    DoublyListNode<TData>* head;

public:
    DoublyLinkedList()
        : head(nullptr)
    {
    }

    ~DoublyLinkedList()
    {
        //throw std::runtime_error("Not implemented yet");
        auto* toDeleteNode = head;
        while (head != nullptr)
        {
            toDeleteNode = head->next;
            delete head;
            head = toDeleteNode;
        }
        delete toDeleteNode;
    }

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    void push_front(const TData& value)
    {
        //throw std::runtime_error("Not implemented yet");
        auto* newNode = new DoublyListNode<TData>(value);
        newNode->next = head;
        head = newNode;
    }

    /**
     * @brief Inserta un nuevo elemento al final de la lista
     *
     * @param value Valor a insertar
     */
    void push_back(const TData& value)
    {
        //throw std::runtime_error("Not implemented yet");
        if (head == nullptr)
            auto* newNode = new DoublyListNode<TData>(value);
        auto* temporalNode = head;
        while (temporalNode->next != nullptr)
            temporalNode = temporalNode->next;
        temporalNode->next = new DoublyListNode<TData>(value);
    }

    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
    void remove_at(size_t position)
    {
        //throw std::runtime_error("Not implemented yet");
        if (head==nullptr) //comprueba que la lista no sea vacia
            return;
        auto* toDeleteNode = head;
        size_t count = 0;
        if (position==count) //si se quiere eliminar la primera posicion
        {
            head = head->next;
            delete toDeleteNode;
        }
        while (toDeleteNode->next != nullptr && position>count) //recorremos la lista hasta la posicion dada o la ultima
        {
            toDeleteNode = toDeleteNode->next;
            count++;
        }
        if (toDeleteNode->next == nullptr) //si el nodo a eliminar es el ultimo no enlazamos
            delete toDeleteNode;
        toDeleteNode->prev->next = toDeleteNode->next; // en caso contrario enlazamos el anterior con
        //el siguiente del nodo a eliminar
        delete toDeleteNode;
    }

    /**
    * @brief Copia los elementos de otra lista
    *
    * @param other Lista de la cual copiar los elementos
    */
    void copy_list(const DoublyLinkedList& other)
    {
        //throw std::runtime_error("Not implemented yet");
        if (other.head == nullptr) //verifica que la otra lista no este vacia
            return;
        auto* copyList = new DoublyListNode<TData>(other.head->data); //creamos una nueva lista copia
        //y copiamos la cabeza de la lista original
        auto* temporalNode = other.head; //inicializa un nodo que recorrera la otra lista
        while (temporalNode->next != nullptr) //recorre hasta el final la otra lista
        {
            temporalNode = temporalNode->next;
            push_front(temporalNode->data); //llama a la funcion push_front para agregar elementos en el
                                            //mismo orden que se recorre la otra lista
        }
    }

    /**
     * @brief Imprime todos los elementos de la lista
     */
    void print() const
    {
        DoublyListNode<TData>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

#endif // LIST_HPP
