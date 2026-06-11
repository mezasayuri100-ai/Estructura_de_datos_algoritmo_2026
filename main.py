# main.py
from empleado_hija import EmpleadoPlanta, EmpleadoPorHora

# ==============================================================================
# LISTA INICIAL DE 10 EMPLEADOS Y HISTORIAL
# ==============================================================================
empleados = [
    EmpleadoPlanta("Carlos Mendoza", "Gerente", 8),
    EmpleadoPlanta("Jorge Rivas", "Supervisor", 12),
    EmpleadoPlanta("Luis Torres", "Operario", 12),
    EmpleadoPlanta("Elena Rostova", "Operario", 3),
    EmpleadoPlanta("Pedro Infante", "Supervisor", 5),
    
    EmpleadoPorHora("Ana Gómez", "Supervisor", 4),
    EmpleadoPorHora("María López", "Operario", 2),
    EmpleadoPorHora("Juan Pérez", "Gerente", 1),
    EmpleadoPorHora("Sofía Castro", "Operario", 6),
    EmpleadoPorHora("Lucas Silva", "Operario", 2)
]

historial_salarios = {}

# ==============================================================================
# LÓGICA PRINCIPAL - MENÚ INTERACTIVO
# ==============================================================================
def menu():
    cargos_orden = ["Gerente", "Supervisor", "Operario"]

    while True:
        print("\n" + "="*50)
        print("SISTEMA DE GESTIÓN DE EMPLEADOS.")
        print("="*50)
        print("1. 👔 MOSTRAR ESCALA DE EMPLEADOS")
        print("2. 💰 CALCULAR SALARIO DE EMPLEABILIDAD")
        print("3. 📄 GENERAR BOLETA DE PAGO")
        print("4. 📊 MOSTRAR EMPLEADO CON MAYOR SALARIO")
        print("5. ⏳ MOSTRAR EMPLEADOS CON MAYOR TIEMPO LABORAL")
        print("6. ➕ AÑADIR NUEVO EMPLEADO")
        print("7. ❌ ELIMINAR EMPLEADO DE LA EMPRESA")
        print("8. 💾 6) GUARDAR REPORTE EN FICHERO (.TXT)")
        print("9. 🚪 SALIR DEL PROGRAMA")
        print("="*50)
        
        opcion = input("Seleccione una opción (1-9): ").strip()

        if opcion == "1":
            print("\n==================================================")
            print("       ESTRUCTURA JERÁRQUICA DE LA EMPRESA        ")
            print("==================================================")
            for cargo in cargos_orden:
                print(f"\n🔹 SECCIÓN: {cargo.upper()}S")
                print("-" * 40)
                
                print("  [CONTRATO DE PLANTA]")
                empleados_planta = [e for e in empleados if e.cargo == cargo and isinstance(e, EmpleadoPlanta)]
                if empleados_planta:
                    for emp in empleados_planta:
                        print(f"   • {emp.nombre:<20} | Antigüedad: {emp.antiguedad} años")
                else:
                    print("   (No hay empleados de Planta en este cargo)")
                
                print("\n  [CONTRATO POR HORA]")
                empleados_hora = [e for e in empleados if e.cargo == cargo and isinstance(e, EmpleadoPorHora)]
                if empleados_hora:
                    for emp in empleados_hora:
                        print(f"   • {emp.nombre:<20} | Antigüedad: {emp.antiguedad} años")
                else:
                    print("   (No hay empleados Por Hora en este cargo)")
                print("-" * 40)

        elif opcion == "2":
            print("\n--- SECCIÓN DE CÁLCULO DE SALARIOS ---")
            print("1. Calcular Empleado de Planta")
            print("2. Calcular Empleado Por Hora")
            sub_opcion = input("Seleccione el tipo de cálculo (1 o 2): ").strip()

            if sub_opcion == "1":
                plantas = [e for e in empleados if isinstance(e, EmpleadoPlanta)]
                if not plantas:
                    print("No hay empleados de planta registrados.")
                    continue
        
                print("\nSeleccione el empleado de Planta a calcular:")
                for idx, emp in enumerate(plantas, 1):
                    print(f"{idx}. {emp.nombre} ({emp.cargo})")
                try:
                    seleccion = int(input("Número de empleado: ")) - 1
                    if 0 <= seleccion < len(plantas):
                        emp_elegido = plantas[seleccion]
                        semanas = int(input(f"¿Cuántas semanas trabajó {emp_elegido.nombre} en el mes?: "))
                        
                        salario = emp_elegido.calcular_salario_final(semanas)
                        historial_salarios[emp_elegido.nombre] = {
                            "cargo": emp_elegido.cargo,
                            "tipo": emp_elegido.tipo,
                            "detalle": f"{semanas} semanas trabajadas",
                            "monto": salario
                        }
                        print(f"✔️ Salario de {emp_elegido.nombre} calculado y guardado.")
                    else:
                        print("❌ Número fuera de rango.")
                except ValueError:
                    print("❌ Entrada inválida. Use números enteros.")

            elif sub_opcion == "2":
                por_horas = [e for e in empleados if isinstance(e, EmpleadoPorHora)]
                if not por_horas:
                    print("No hay empleados por hora registrados.")
                    continue

                print("\nSeleccione el empleado Por Hora a calcular:")
                for idx, emp in enumerate(por_horas, 1):
                    print(f"{idx}. {emp.nombre} ({emp.cargo})")
                try:
                    seleccion = int(input("Número de empleado: ")) - 1
                    if 0 <= seleccion < len(por_horas):
                        emp_elegido = por_horas[seleccion]
                        horas = int(input(f"¿Cuántas horas totales trabajó {emp_elegido.nombre} en el mes?: "))
                        
                        salario = emp_elegido.calcular_salario_final(horas)
                        historial_salarios[emp_elegido.nombre] = {
                            "cargo": emp_elegido.cargo,
                            "tipo": emp_elegido.tipo,
                            "detalle": f"{horas} horas trabajadas",
                            "monto": salario
                        }
                        print(f"✔️ Salario de {emp_elegido.nombre} calculado y guardado.")
                    else:
                        print("❌ Número fuera de rango.")
                except ValueError:
                    print("❌ Entrada inválida. Use números enteros.")
            else:
                print("❌ Opción incorrecta.")
                
        elif opcion == "3":
            print("\n--- REPORTE DE BOLETAS DE PAGO GENERADAS ---")
            if not historial_salarios:
                print("No hay boletas generadas aún.")
                continue

            for nombre, datos in historial_salarios.items():
                print("\n+================================================+")
                print("|                BOLETA DE PAGO                 |")
                print("+================================================+")
                print(f"| Nombre  : {nombre:<35}|")
                print(f"| Cargo   : {datos['cargo']:<35}|")
                print(f"| Tipo    : {datos['tipo']:<35}|")
                print(f"| Detalle : {datos['detalle']:<35}|")
                print(f"| Salario : ${datos['monto']:<34.2f}|")
                print("+================================================+")
                
        elif opcion == "4":
            print("\n--- EMPLEADO CON MAYOR SALARIO ---")
            if not historial_salarios:
                print("No hay registros de salarios calculados.")
                continue
            nombre_mayor, datos_mayor = max(
                historial_salarios.items(), 
                key=lambda x: x[1]["monto"]
                )
            print(f"👑 El empleado con mayor salario es: {nombre_mayor}")
            print(f"   Cargo: {datos_mayor['cargo']} | Salario: ${datos_mayor['monto']:.2f}")

        elif opcion == "5":
            print("\n--- EMPLEADOS CON MAYOR TIEMPO LABORAL ---")
            if not empleados:
                print("No hay empleados registrados.")
                continue
            max_antiguedad = max(e.antiguedad for e in empleados)
            print(f"Antigüedad máxima alcanzada: {max_antiguedad} años")
            for e in empleados:
                if e.antiguedad == max_antiguedad:
                    print(f" • {e.nombre} ({e.cargo})")

        elif opcion == "6":
            print("\n--- AÑADIR NUEVO EMPLEADO ---")
            nombre = input("Nombre: ")
            cargo = input("Cargo (Gerente/Supervisor/Operario): ").strip()
            try:
                antiguedad = int(input("Años de antigüedad: "))
                tipo = input("Tipo (1: Planta, 2: Por Hora): ").strip()
                if tipo == "1":
                    empleados.append(EmpleadoPlanta(nombre, cargo, antiguedad))
                    print("Empleado de Planta añadido con éxito.")
                elif tipo == "2":
                    empleados.append(EmpleadoPorHora(nombre, cargo, antiguedad))
                    print("Empleado Por Hora añadido con éxito.")
                else:
                    print("Tipo inválido.")
            except ValueError:
                print("Error de datos.")

        elif opcion == "7":
            print("\n--- ELIMINAR EMPLEADO ---")
            for idx, emp in enumerate(empleados, 1):
                print(f"{idx}. {emp.nombre} ({emp.cargo})")
            try:
                sel = int(input("Número de empleado a dar de baja: ")) - 1
                if 0 <= sel < len(empleados):
                    eliminado = empleados.pop(sel)
                    historial_salarios.pop(eliminado.nombre, None)
                    print(f"❌ El empleado {eliminado.nombre} fue removido.")
                else:
                    print("❌ Número fuera de rango.")
            except ValueError:
                print("❌ Entrada inválida.")

        elif opcion == "8":
            print("\n--- GENERANDO ARCHIVO DE TEXTO REPORTE (.TXT) ---")
            try:
                with open("reporte_empleados.txt", "w", encoding="utf-8") as f:
                    f.write("==================================================\n")
                    f.write("       REPORTE DE PERSONAL Y NÓMINA DE EMPRESA\n")
                    f.write("==================================================\n\n")

                    f.write("1) LISTADO ACTUAL DE EMPLEADOS REGISTRADOS:\n")
                    f.write(f"{'Nombre':<25} | {'Cargo':<12} | {'Tipo Contrato':<15} | Antigüedad\n")
                    f.write("-" * 70 + "\n")

                    for e in empleados:
                        f.write(
                            f"{e.nombre:<25} | {e.cargo:<12} | {e.tipo:<15} | {e.antiguedad} años\n"
                        )

                    f.write("\n" + "=" * 50 + "\n")
                    f.write("2) HISTORIAL DE SALARIOS CALCULADOS:\n")
                    f.write("-" * 50 + "\n")

                    if historial_salarios:
                        for nombre, datos in historial_salarios.items():
                            f.write(
                                f"{nombre:<25} | {datos['cargo']:<12} | "
                                f"${datos['monto']:.2f} ({datos['detalle']})\n"
                            )
                    else:
                        f.write("No se han calculado salarios todavía.\n")

                print("💾 ¡Fichero reporte_empleados.txt generado exitosamente!")

            except Exception as e:
                print(f"Ocurrió un error al guardar el fichero: {e}")

        elif opcion == "9":
            print("\n🚪 Saliendo del sistema de gestión. ¡Hasta luego!")
            break

        else:
            print("❌ Opción no válida. Intente de nuevo.")

if __name__ == "__main__":
    menu()