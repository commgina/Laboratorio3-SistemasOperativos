# Cuestionario

### 4.1. ¿Cuáles son los tipos de type descriptors que podemos encontrar en /proc//fd?

Los tipos que podemos encontrar son:
- REG: Regular file
- DIR: Diretory file
- CHR: Character special file
- FIFO: First input firt output

### 4.2. Suponiendo que un usuario está ejecutando el proceso pid 1212, ¿Es válida la ejecución del siguiente comando desde una terminal nueva? % echo “Hello, world.” >> /proc/1212/fd/1

El file descriptor 0 esta dedicado a standard input, el 1 a standar output y el 2 a standar error. Por lo tanto, ejecutar echo “Hello, world.” >> /proc/1212/fd/1 es escribir _Hello, world_ en el stoud del file descriptor y se imprimira por consola. Teniendo en cuenta que el proceso actual es el proc/self/fd, dare un ejemplo:

```c
$ echo "hello world" > /proc/self/fd/1
hello world
```

### 4.3. Qué diferencia hay entre hard y soft limits?


- hard limit: es el maximo valor admitido por el soft limit. Cualquier cambio al hard limit requiere acceso root
- soft limit: es el valor que Linux usa para limitar los recursos del sistema para los procesos. No puede ser mayor al hard limit.
Cualquier usuario o proceso puede aumentar los soft limits hasta el nivel de los hard limits.