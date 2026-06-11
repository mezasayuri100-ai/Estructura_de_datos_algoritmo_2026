# empleado_hija.py
from empleado_padre import Empleado

class EmpleadoPlanta(Empleado):
    """Clase Hija: Empleados con contrato fijo de 40 horas semanales."""
    def __init__(self, nombre: str, cargo: str, antiguedad: int):
        super().__init__(nombre, cargo, antiguedad, "Planta")
        self.horas_semanales = 40

    def calcular_salario_final(self, semanas_trabajadas: int) -> float:
        tarifa_hora = self.TARIFAS.get(self.cargo, 50.0)
        salario_semanal = tarifa_hora * self.horas_semanales
        return salario_semanal * semanas_trabajadas


class EmpleadoPorHora(Empleado):
    """Clase Hija: Empleados con jornadas flexibles por horas."""
    def __init__(self, nombre: str, cargo: str, antiguedad: int):
        super().__init__(nombre, cargo, antiguedad, "Por Hora")

    def calcular_salario_final(self, horas_totales: int) -> float:
        tarifa_hora = self.TARIFAS.get(self.cargo, 50.0)
        return tarifa_hora * horas_totales# empleado_hija.py
from empleado_padre import Empleado

class EmpleadoPlanta(Empleado):
    """Clase Hija: Empleados con contrato fijo de 40 horas semanales."""
    def __init__(self, nombre: str, cargo: str, antiguedad: int):
        super().__init__(nombre, cargo, antiguedad, "Planta")
        self.horas_semanales = 40

    def calcular_salario_final(self, semanas_trabajadas: int) -> float:
        tarifa_hora = self.TARIFAS.get(self.cargo, 50.0)
        salario_semanal = tarifa_hora * self.horas_semanales
        return salario_semanal * semanas_trabajadas


class EmpleadoPorHora(Empleado):
    """Clase Hija: Empleados con jornadas flexibles por horas."""
    def __init__(self, nombre: str, cargo: str, antiguedad: int):
        super().__init__(nombre, cargo, antiguedad, "Por Hora")

    def calcular_salario_final(self, horas_totales: int) -> float:
        tarifa_hora = self.TARIFAS.get(self.cargo, 50.0)
        return tarifa_hora * horas_totales 