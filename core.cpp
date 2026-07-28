#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <thread>
#include <sstream>
#include <iomanip>
#include <windows.h>

// Estructura interna para representar los registros de la Base de Datos
struct Usuario {
    double saldo;
    std::string token_tarjeta;
    bool bloqueado;
};

// CONFIGURACIÓN Y BASE DE DATOS SIMULADA EN MEMORIA
std::unordered_map<std::string, Usuario> DB_USUARIOS = {
    {"usr_001", {5000.0, "token_valido_001", false}},
    {"usr_002", {50.0, "token_valido_002", false}}
};

std::unordered_map<std::string, std::vector<double>> HISTORIAL_COMPRAS;
std::unordered_map<std::string, int> INTENTOS_LOGIN;
const std::string SECRET_KEY_CANAL = "SafePay_Secret_Key_2026_###";

// Hash SHA-256
std::string simular_sha256(const std::string& datos) {
    unsigned long hash = 5381;
    for (char c : datos) {
        hash = ((hash << 5) + hash) + c;
    }
    std::stringstream ss;
    ss << std::hex << std::setw(16) << std::setfill('0') << hash;
    return ss.str();
}

// LAS 5 FUNCIONES PRINCIPALES PROGRAMADAS

// F1: Tokenización de Tarjetas mediante Dispersión
std::string tokenizar_tarjeta(const std::string& numero_tarjeta, const std::string& cvv) {
    if (numero_tarjeta.length() != 16) {
        throw std::invalid_argument("Numero de tarjeta invalido (deben ser 16 digitos).");
    }
    std::string sal_aleatoria = "sal_xyz_987"; // Simulación de sal criptográfica estricta
    return simular_sha256(numero_tarjeta + cvv + sal_aleatoria);
}

// F2: Algoritmo Antifraude por Frecuencia (Ventana Flotante de Tiempo)
bool detectar_anomalia_frecuencia(const std::string& id_usuario) {
    // Obtiene la marca de tiempo actual en segundos de alta precisión
    auto ahora = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count() / 1000.0;

    HISTORIAL_COMPRAS[id_usuario].push_back(ahora);

    // Filtrar la lista dinámica (std::vector) reteniendo solo marcas de los últimos 5 segundos
    std::vector<double> compras_recientes;
    for (double t : HISTORIAL_COMPRAS[id_usuario]) {
        if (ahora - t <= 5.0) {
            compras_recientes.push_back(t);
        }
    }
    HISTORIAL_COMPRAS[id_usuario] = compras_recientes;

    // Si excede el umbral de 3 compras en 5 segundos, muta el estado lúdico a bloqueado
    if (compras_recientes.size() > 3) {
        if (DB_USUARIOS.find(id_usuario) != DB_USUARIOS.end()) {
            DB_USUARIOS[id_usuario].bloqueado = true;
        }
        return false; // Anomalía detectada
    }
    return true; // Transacción segura
}

// F3: Verificación de Integridad de Datos del Canal (Anti-MitM)
bool verificar_integridad_canal(const std::string& datos_mensaje, const std::string& hash_recibido) {
    std::string hash_esperado = simular_sha256(datos_mensaje + SECRET_KEY_CANAL);
    
    // Comparación segura bit a bit para evitar ataques de temporización
    if (hash_esperado.length() != hash_recibido.length()) return false;
    int resultado = 0;
    for (size_t i = 0; i < hash_esperado.length(); ++i) {
        resultado |= (hash_esperado[i] ^ hash_recibido[i]);
    }
    return resultado == 0;
}

// F4: Control de Acceso Perimetral (Anti-Fuerza Bruta)
std::string gestionar_alertas_accesos_fallidos(const std::string& id_usuario, bool exito_login) {
    if (exito_login) {
        INTENTOS_LOGIN[id_usuario] = 0;
        return "Acceso concedido.";
    }
    
    INTENTOS_LOGIN[id_usuario]++;
    if (INTENTOS_LOGIN[id_usuario] >= 3) {
        return "CRITICAL ALERT: Intento de intrusion detectado para '" + id_usuario + "'. Cuenta suspendida.";
    }
    return "Acceso denegado. Intento " + std::to_string(INTENTOS_LOGIN[id_usuario]) + " de 3.";
}

// F5: Orquestador Seguro de Procesamiento de Transacciones
std::pair<bool, std::string> procesar_transaccion_segura(const std::string& id_usuario, double monto, const std::string& token_tarjeta) {
    if (DB_USUARIOS.find(id_usuario) == DB_USUARIOS.end()) {
        return {false, "Error: Usuario no registrado."};
    }
    
    Usuario& usuario = DB_USUARIOS[id_usuario];
    if (usuario.bloqueado) {
        return {false, "Transaccion rechazada: Cuenta bloqueada por seguridad."};
    }
    if (usuario.token_tarjeta != token_tarjeta) {
        return {false, "Transaccion rechazada: Token de tarjeta invalido."};
    }
    if (usuario.saldo < monto) {
        return {false, "Transaccion rechazada: Fondos insuficientes."};
    }
    
    usuario.saldo -= monto;
    return {true, "Transaccion procesada con exito de forma segura."};
}
// DECLARACIÓN DE LAS 15 FUNCIONES TEÓRICAS ADICIONALES (ARQUITECTURA)
void registrar_usuario(void* datos) {}
void autenticar_administrador(void* credenciales) {}
void actualizar_saldo_cuenta(std::string id, double m) {}
void generar_recibo_fiscal(std::string id_tx) {}
void consultar_historial_pagos(std::string id) {}
void reversar_transaccion(std::string id_tx) {}
void vincular_cuenta_bancaria(void* banco) {}
void configurar_limites_montos(std::string id, double lim) {}
void notificar_correo_comprobante(std::string email, std::string msg) {}
void exportar_auditoria_csv() {}
void renovar_token_sesion(std::string id_sess) {}
void verificar_caducidad_tarjeta(int m, int a) {}
void aplicar_descuento_promocional(std::string cod) {}
void calcular_comisiones_plataforma(double m) {}
void archivar_datos_historicos() {}

void mostrar_menu() {
    int opcion;
    do {
        std::cout << "\n=======================================================\n";
        std::cout << "      SAFEPAY SYSTEM - TERMINAL DE OPERACIONES (C++)\n";
        std::cout << "=======================================================\n";
        std::cout << "1. [F1] Probar Tokenizacion Criptografica de Tarjeta\n";
        std::cout << "2. [F2] Simular Ataque de Rafaga en Tiempo Real\n";
        std::cout << "3. [F3] Simular Ataque Man-in-the-Middle (Canal)\n";
        std::cout << "4. [F4] Simular Ataque de Fuerza Bruta en Login\n";
        std::cout << "5. [F5] Ejecutar Transaccion Regular Segura\n";
        std::cout << "6. Ver Estado Actual de la Base de Datos\n";
        std::cout << "7. Salir del Sistema\n";
        std::cout << "Seleccione una accion (1-7): ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::string tarjeta, cvv;
            std::cout << "Numero de tarjeta (16 digitos): "; std::cin >> tarjeta;
            std::cout << "CVV (3 digitos): "; std::cin >> cvv;
            try {
                std::cout << "🔒 Token Generado: " << tokenizar_tarjeta(tarjeta, cvv) << "\n";
            } catch (const std::exception& e) {
                std::cout << "❌ Error: " << e.what() << "\n";
            }
        } else if (opcion == 2) {
            std::cout << "Enviando 5 transacciones en milisegundos para 'usr_001'...\n";
            for (int i = 1; i <= 5; ++i) {
                std::cout << "Peticion #" << i << " enviada...\n";
                if (!detectar_anomalia_frecuencia("usr_001")) {
                    std::cout << "🚨 ANOMALIA DETECTADA: Cuenta 'usr_001' congelada automáticamente.\n";
                    break;
                }
               Sleep(100);
            }
        } else if (opcion == 3) {
            std::string msg = "monto=50";
            std::string hash_correcto = simular_sha256(msg + SECRET_KEY_CANAL);
            std::cout << "Interceptando red... Modificando mensaje a 'monto=999999'\n";
            if (!verificar_integridad_canal("monto=999999", hash_correcto)) {
                std::cout << "🛡️ RECHAZO CRIPTOGRAFICO: El canal detecto la alteracion.\n";
            }
        } else if (opcion == 4) {
            for (int i = 0; i < 3; ++i) {
                std::cout << gestionar_alertas_accesos_fallidos("admin_root", false) << "\n";
            }
        } else if (opcion == 5) {
            std::string uid, token; double monto;
            std::cout << "ID Usuario: "; std::cin >> uid;
            std::cout << "Monto ($): "; std::cin >> monto;
            std::cout << "Token Tarjeta: "; std::cin >> token;
            auto res = procesar_transaccion_segura(uid, monto, token);
            std::cout << (res.first ? "✅ " : "❌ ") << res.second << "\n";
        } else if (opcion == 6) {
           for (const auto& pair : DB_USUARIOS) {
               const auto& user = pair.first;
               const auto& datos = pair.second;
                std::cout << "Usuario: " << user << " | Saldo: $" << datos.saldo << " | Bloqueado: " << (datos.bloqueado ? "Si" : "No") << "\n";
            }
        }
    } while (opcion != 7);
}

int main() {
    mostrar_menu();
    return 0;
}