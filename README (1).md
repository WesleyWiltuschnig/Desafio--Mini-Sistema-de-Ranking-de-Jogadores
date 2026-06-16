# ⚽ Sistema de Ranking — Copa do Mundo

## Informações do Aluno

- **Nome do aluno:** Wesley Wiltuschnig
- **Data:** 15/06/2026
- **Disciplina:** Estrutura de Dados

---

## 📋 Descrição do Desafio

Mini sistema em linguagem C para controlar jogadores e suas pontuações, com tema da **Copa do Mundo**.  
Cada jogador representa um atleta com `id`, `nome` e `pontos` (gols marcados).

O sistema permite:
- Cadastrar até 20 jogadores
- Listar todos os jogadores do elenco
- Buscar jogador por ID
- Ordenar o ranking por pontuação (gols) em ordem decrescente
- Exibir o artilheiro campeão

---

## 🛠️ Como Compilar

```bash
gcc main.c -o ranking
```

## ▶️ Como Executar

```bash
./ranking
```

---

## 🖥️ Exemplo de Uso

```
🏟️  Bem-vindo ao Sistema de Ranking da Copa do Mundo! 🏆

========= MENU COPA DO MUNDO =========
1 - ⚽ Cadastrar jogador
2 - 📋 Listar jogadores
3 - 🔍 Buscar jogador por ID
4 - 📊 Ordenar ranking por gols
5 - 🥇 Exibir artilheiro (campeão)
0 - 🚪 Sair
======================================
```

---

## 📁 Estrutura do Repositório

```
.
├── main.c       # Código-fonte principal
└── README.md    # Este arquivo
```

---

## ✅ Requisitos Atendidos

- [x] Cadastro de até 20 jogadores
- [x] Uso de `struct`
- [x] Uso de vetor de structs
- [x] Uso de funções
- [x] Busca por ID
- [x] Ordenação por pontuação (decrescente)
- [x] Exibição do campeão (artilheiro)
- [x] Menu com `switch`
- [x] Compila e executa corretamente
