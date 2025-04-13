#ifndef EVENTO_H
#define EVENTO_H

#include <string>
#include <iostream>


enum class TipoEvento {
    Visit,
    Exploration,
    Raid,
    Construction,
    Reparation,
    Unknown
};


inline std::string tipoEventoToString(TipoEvento tipo) {
    if (tipo == TipoEvento::Visit) return "Visita";
    if (tipo == TipoEvento::Exploration) return "Exploración";
    if (tipo == TipoEvento::Raid) return "Ataque";
    if (tipo == TipoEvento::Construction) return "Construcción";
    if (tipo == TipoEvento::Reparation) return "Reparación";
    return "Desconocido";
}


struct Evento {
    TipoEvento type_;
    std::string description_;

    Evento(TipoEvento type, const std::string& description)
        : type_(type), description_(description) {}

    /// Muestra el evento por consola
    void Imprimir() const {
        std::cout << "[Evento: " << tipoEventoToString(type_) << "] "
                  << description_ << "\n";
    }
};

inline std::string descripcionEvento(const Evento& e) {
    if (e.type_ == TipoEvento::Visit) {
        return "¡Llegó alguien al refugio!";
    } else if (e.type_ == TipoEvento::Exploration) {
        return "¡Exploración en proceso!";
    } else if (e.type_ == TipoEvento::Raid) {
        return "¡Están atacando al refugio!";
    } else if (e.type_ == TipoEvento::Construction) {
        return "¡Se está construyendo algo nuevo!";
    } else if (e.type_ == TipoEvento::Reparation) {
        return "¡Reparación en proceso!";
    } else {
        return "Evento desconocido.";
    }
}

#endif // EVENTO_H