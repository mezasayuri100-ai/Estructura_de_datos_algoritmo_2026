# empleado_padre.py

class Empleado:
    """Clase base (Clase Padre) con las tarifas oficiales de la empresa."""
    TARIFAS = {"Gerente": 100.0, "Supervisor": 80.0, "Operario": 50.0}

    def __init__(self, nombre: str, cargo: str, antiguedad: int, tipo: str):
        self.nombre = nombre
        self.cargo = cargo.capitalize()
        self.antiguedad = antiguedad  # Años en la empresa
        self.tipo = tipo

    def calcular_salario_final(self, factor: int) -> float:
        pass

    def __str__(self) -> str:
        return f"[{self.tipo}] {self.nombre:<20} | Antigüedad: {self.antiguedad} años"# empleado_padre.py

class Empleado:
    """Clase base (Clase Padre) con las tarifas oficiales de la empresa."""
    TARIFAS = {"Gerente": 100.0, "Supervisor": 80.0, "Operario": 50.0}

    def __init__(self, nombre: str, cargo: str, antiguedad: int, tipo: str):
        self.nombre = nombre
        self.cargo = cargo.capitalize()
        self.antiguedad = antiguedad  # Años en la empresa
        self.tipo = tipo

    def calcular_salario_final(self, factor: int) -> float:
        pass

    def __str__(self) -> str:
        return f"[{self.tipo}] {self.nombre:<20} | Antigüedad: {self.antiguedad} años"