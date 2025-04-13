#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

/**
 * @brief Estructura de datos tipo Pila (LIFO - Last In, First Out)
 *
 * @tparam TData Tipo de dato almacenado en la pila
 */
template<typename TData>
class Stack
{
private:
    /**
     * @brief Nodo de la pila
     */
    struct Node
    {
        TData data; ///< Valor almacenado
        Node* next; ///< Puntero al siguiente nodo

        Node(const TData& data, Node* next = nullptr)
            : data(data)
            , next(next)
        {
        }
    };

    Node* m_top;   ///< Puntero al nodo superior (cima)
    size_t m_size; ///< Cantidad de elementos en la pila

public:
    /**
     * @brief Constructor por defecto
     */
    Stack()
        : m_top(nullptr)
        , m_size(0)
    {
    }

    /**
     * @brief Destructor: libera todos los nodos
     */
    ~Stack()
    {
        while (!isEmpty())
         pop();
    }

    /**
     * @brief Agrega un elemento en la cima de la pila
     *
     * @param value Valor a insertar
     */
    void push(const TData& value)
    {
        Node* newNode = new Node(value, m_top);
        m_top = newNode;
        ++m_size;
    }

    /**
     * @brief Elimina el elemento superior de la pila
     *
     * @throws std::underflow_error si la pila está vacía
     */
    void pop()
    {
        if (isEmpty()) //verifica si la pila esta vacia
        {
            throw std::underflow_error("Stack is empty");
        }
        auto* toDeleteNode = m_top; //crea un nuevo nodo y le asignamos la cima
        m_top = m_top->next; //la nueva cima es el proximo
        delete toDeleteNode; //eliminaa la anterior cima
        --m_size; //actualiza el tamaño de la pila
    }

    /**
     * @brief Devuelve una referencia al elemento superior (mutable)
     *
     * @return TData& referencia al valor
     * @throws std::underflow_error si la pila está vacía
     */
    TData& top()
    {
        if (isEmpty())
        throw std::underflow_error("Stack is empty");
        return m_top->data;
    }

    /**
     * @brief Devuelve una referencia constante al elemento superior
     *
     * @return const TData& referencia constante al valor
     * @throws std::underflow_error si la pila está vacía
     */
    const TData& top() const
    {
        if (isEmpty())
        throw std::underflow_error("Stack is empty");
        return m_top->data;
    }

    /**
     * @brief Verifica si la pila está vacía
     *
     * @return true si no hay elementos
     * @return false si hay al menos un elemento
     */
    bool isEmpty() const
    {
        return m_top == nullptr;
    }

    /**
     * @brief Devuelve la cantidad de elementos en la pila
     *
     * @return size_t tamaño de la pila
     */
    size_t size() const
    {
        return m_size;
    }
};

#endif // STACK_HPP
