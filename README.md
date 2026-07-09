# Jota Labs

Uma coleção de pequenos laboratórios desenvolvidos para estudar OpenGL, computação gráfica e técnicas de renderização por meio de projetos práticos e independentes.

---

## Objetivo

Cada laboratório aborda um conceito específico da computação gráfica.

Os projetos são independentes entre si e foram criados para permitir experimentação e aprendizado incremental, sem a necessidade de desenvolver uma engine completa.

---

## Laboratórios

- [x] [01 - Shader Playground](./01_ShaderPlayground/)
- [x] [02 - Texture Laboratory](./02_TextureLaboratory/)

---

## Como compilar

> OBS: Apenas testado no **Linux**!

### Requisitos

* CMake
* GLFW
* GLM

### Instruções

1. Clone este repositório e escolha o projeto que você quer estudar.

2. Entre na pasta do projeto e gere os arquivos do CMake usando:
    ```bash
    cmake -S . -B build
    ```
* ou use o script pronto **(Apenas Linux)**:
    ```bash
    ./scripts/generate.sh
    ```

3. Compile o projeto e execute:
    ```bash
    cmake --build build
    cd build
    ./JotaLab
    ```

* ou use o script pronto **(Apenas Linux)**:
    ```bash
    ./scripts/compile.sh
    ./scripts/run.sh
    ```

---

## Licença

Esse projeto está sob a licença [MIT](LICENSE)