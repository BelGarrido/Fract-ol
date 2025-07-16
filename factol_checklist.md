# ✅ Proyecto fract-ol - Checklist 42

**Fecha de inicio:** 2025-05-13

---

## 🔹 1. Requisitos Generales

- [✅] Solo se permite el uso de la librería **MLX42**
- [✅] Sin fugas de memoria (valgrind clean)
- [ ] Usar errores de perror etc Escribir Error\n en stderr
- [ ] Código norminette compliant
- [✅] `make` compila sin errores ni warnings
- [✅] `ESC` o cerrar ventana finaliza el programa correctamente

---

## 🔹 2. Argumentos y Entrada

- [✅] Acepta argumentos válidos: `"mandelbrot"`, `"julia <real> <imag>"`, `"burningship"`
- [✅] Validación de argumentos numéricos y cantidad correcta
- [✅] Mensajes de error claros si los argumentos son inválidos

---

## 🔹 3. Representación Gráfica

- [✅] Ventana se abre correctamente
- [✅] Se muestra el fractal seleccionado
- [✅] [0 ... 799] -> [-2 ... 2]
- [✅] Comportamiento fluido con la ventana (minimizar, cambiar, etc.)
- [✅] ESC y botón de cerrar ventana funcionan correctamente
- [✅] WIDTH and HEIGHT --> determinadas por eventos hook

---

## 🔹 4. Interacción Obligatoria

- [✅] Rueda del ratón → zoom in/out   no esta bien implementado mi zoom: porque amplia las cantidad de pixeles a pintar --> Opción 2: Mantener el tamaño, pero cambiar la escala del sistema de coordenadas
- [ ] Zoom centrado en el puntero
- [ ] Julia: modificar parámetros con movimiento del ratón
- [ ] Activar/desactivar esa modificación con una tecla

---

## 🔹 5. Fractales Obligatorios

- [✅] Mandelbrot
- [✅] Julia
- [ ] (Bonus) Burning Ship

---

## 🔹 6. Bonus

- [ ] Movimiento con teclas (WASD o flechas)
- [ ] Cambio de paleta de colores
- [ ] Zoom animado
- [ ] Otros fractales (Newton, Tricorn, etc.)
- [ ] Mostrar info (zoom, coords, tipo fractal)

---

## 📦 Organización del Código

- [ ] Parsing de argumentos separado
- [ ] Inicialización de MLX clara
- [ ] Cálculo de fractales modular
- [ ] Hooks y eventos bien gestionados
- [ ] Uso de `t_fractal` con:
  - [ ] `mlx`, `img`
  - [ ] `zoom`, `offset_x`, `offset_y`
  - [ ] `tipo_fractal`, `julia_real`, `julia_imag`
- [ ] Funciones pequeñas, legibles y bien nombradas

---

_¡Marca los ítems a medida que avances!_
