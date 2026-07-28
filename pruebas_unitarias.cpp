#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <cassert>
#include <chrono>
#include <unordered_map>

// --- INCLUIMOS EL CORE SIN CONFLICTO DE MAIN ---
#define main core_main
#include "core.cpp"
#undef main
// -----------------------------------------------

void test_01_bucle_ataque_fuerza_bruta() {
    std::cout << "test_01_bucle_ataque_fuerza_bruta ... ";
    std::string res;
    for (int i = 0; i < 3; ++i) {
        res = gestionar_alertas_accesos_fallidos("usr_hacker", false);
    }
    // Aserción:
    assert(res.find("CRITICAL ALERT") != std::string::npos);
    std::cout << "PASSED (OK)\n";
}

void test_02_estres_transacciones_concurrentes() {
    std::cout << "[TEST 02] Ejecutando prueba de ráfaga de transacciones..." << std::endl;

    // 1. Definimos el usuario para la prueba
    std::string usuario_test = "usr_001";
    DB_USUARIOS[usuario_test].bloqueado = false; // Nos aseguramos de que empiece desbloqueado

    // 2. Definimos la acción que simula la petición del usuario
    auto enviar_peticion = [&]() {
        detectar_anomalia_frecuencia(usuario_test);
    };

    // 3. Simulamos la ráfaga enviando 5 peticiones seguidas
    for (int i = 0; i < 5; i++) {
        enviar_peticion();
    }

    // 4. Comprobamos que el algoritmo antifraude haya bloqueado la cuenta
    assert(DB_USUARIOS[usuario_test].bloqueado == true);
    std::cout << "  -> PASO: Sistema detecto el ataque de rafaga y bloqueo la cuenta con exito." << std::endl;
}

void test_03_carga_procesamiento_secuencial() {
    std::cout << "test_03_carga_procesamiento_secuencial ... ";
    std::string id_user = "usr_002";
    DB_USUARIOS[id_user].saldo = 10000.0;
    std::string token = DB_USUARIOS[id_user].token_tarjeta;

    // Ráfaga masiva continua de 100 transacciones secuenciales
    for (int i = 0; i < 100; ++i) {
        auto res = procesar_transaccion_segura(id_user, 1.0, token);
        assert(res.first == true);
    }
    assert(DB_USUARIOS[id_user].saldo == 9900.0);
    std::cout << "PASSED (OK)\n";
}

void test_04_integridad_mensaje_alterado() {
    std::cout << "test_04_integridad_mensaje_alterado ... ";
    std::string msg_orig = "monto=100";
    std::string msg_alt = "monto=999";
    std::string hash_valido = simular_sha256(msg_orig + SECRET_KEY_CANAL);

    assert(verificar_integridad_canal(msg_alt, hash_valido) == false);
    std::cout << "PASSED (OK)\n";
}

void test_05_tokenizacion_segura() {
    std::cout << "test_05_tokenizacion_segura ... ";
    std::string token = tokenizar_tarjeta("1234567812345678", "123");
    assert(token.length() == 16); // Verifica la longitud de salida fija
    std::cout << "PASSED (OK)\n";
}

void test_06_falsos_positivos_antifraude() {
    std::cout << "test_06_falsos_positivos_antifraude ... ";
    assert(detectar_anomalia_frecuencia("usr_legitimo") == true);
    std::cout << "PASSED (OK)\n";
}

int main() {
    std::cout << "EJECUTANDO EL ENTORNO DE CONTROL DE CALIDAD TRANSACCIONAL\n";
    std::cout << "---------------------------------------------------------\n";
    test_01_bucle_ataque_fuerza_bruta();
    test_02_estres_transacciones_concurrentes();
    test_03_carga_procesamiento_secuencial();
    test_04_integridad_mensaje_alterado();
    test_05_tokenizacion_segura();
    test_06_falsos_positivos_antifraude();
    std::cout << "---------------------------------------------------------\n";
    std::cout << "TODAS LAS PRUEBAS PASARON EXITOSAMENTE. RETORNO: 0\n";
    return 0;
}