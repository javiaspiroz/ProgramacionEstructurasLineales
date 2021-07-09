#include <cstdlib>
#include <fmt/format.h>
#include <iostream>

using namespace std;

struct Node_base{
    Node_base* prev = nullptr;//puntero al Node_base anterior
    Node_base* next = nullptr;//puntero al siguiente Node_base

    auto hook(Node_base* p) -> void{//el nodo que llame a esta funcion se situara delante del nodo p
        this->next = p;
        this->prev=p->prev;
        (p->prev)->next = this;
        p->prev= this;
    }

    auto unhook() -> void{//el nodo que invoca esta funcion se desliga de la lista y se autoenlaza
        (this->prev)->next=this->next;
        (this->prev)->prev = this->prev;
        this->next=this;
        this->prev=this;
        //this->prev = this->next = this; //otra forma de hacer las dos líneas anteriores
        //si omitiesemos los this no pasaria nada ya que es un puntero implicito
    }

    //Funcion swap en el blog
};

template <typename T>
class List{
    struct Node : Node_base {
        T dat; //dato almacenado en el nodo
        Node(T const& d) : Node_base{}, dat{d} { }
    };

    Node_base dnb_; //nodo centinela (o de control) como unico dato privado
public:

    struct ListIterator {//struct copiado del blog
        Node_base* node;
        explicit ListIterator(Node_base* node_ = nullptr) noexcept
            : node{node_} { }

        bool operator==(ListIterator const& rhs) const noexcept { return node == rhs.node; }
        bool operator!=(ListIterator const& rhs) const noexcept { return node != rhs.node; }

        T& operator*() const{
            return static_cast<Node*>(node)->dat; // downcasting seguro
        }

        T* operator->() const noexcept{
            return &static_cast<Node*>(node)->dat; // ídem
        }

        ListIterator& operator++() noexcept {// prefijo
            node = node->next;
            return *this;
        }

        ListIterator operator++(int) noexcept {// sufijo
            auto tmp = *this;
            node = node->next;
            return tmp;
        }

        ListIterator& operator--() noexcept {// prefijo
            node = node->prev;
            return *this;
        }

        ListIterator operator--(int) noexcept {// sufijo
            auto tmp = *this;
            node = node->prev;
            return tmp;
        }
    };

    //constructor por defecto: crea una lista vacia
    //el nodo centinela se referencia a si mismo:
    List()
        : dnb_{&dnb_, &dnb_} { }

    auto push_back(T const& value) -> void{
        Node* p = new Node{value};
        p->hook(&dnb_);
    }

    auto clear() -> void{ //borrar el contenido y dejar la lista vacia
        Node_base* current = dnb_.next; //apunta al primer nodo
        while (current != &dnb_){//si no hemos regresado al nodo centinela...
            Node_base* tmp = current;
            current = current->next;
            delete static_cast<Node*>(tmp);
        }
        //hacemos que el nodo centinela se referencia a si mismo (lista vacia)
        dnb_.next = dnb_.prev = &dnb_;
    }

    //destructor de la lista: destruye todos los nodos cuando la lista salga del ambito de donde fue declarada
    ~List() { clear(); }

    auto size() const -> int{//retorna el numero de nodos
        int total = 0;
        Node_base* p = dnb_.next;
        while (p != &dnb_){
            ++total;
            p = p->next;
        }
        return total;
    }
};

auto main() -> int {
    auto lista = List<int>{};
    lista.push_back(1);
    lista.push_back(2);
    cout << lista.size();
    lista.clear();
    lista.push_back(7);
    lista.push_back(8);
    cout << lista.size();
    return EXIT_SUCCESS;
} //lista.~List()