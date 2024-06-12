#include <stdio.h>
#include <stdlib.h>

// Funzione per mostrare l'introduzione
void mostraIntroduzione() {
    printf("Benvenuti al gioco di domande e risposte sugli anime!\n");
    printf("Rispondete alle domande e totalizzate il massimo punteggio.\n\n");
}

// Funzione per mostrare il menu iniziale
void mostraMenu() {
    printf("Scegliere un'opzione:\n");
    printf("A) Iniziare una nuova partita\n");
    printf("B) Uscire dal gioco\n");
}

// Funzione per ottenere la scelta dell'utente
char ottieniScelta() {
    char scelta;
    printf("Inserire la scelta (A/B): ");
    scanf(" %c", &scelta);
    return scelta;
}

// Funzione per gestire una nuova partita
void nuovaPartita() {
    char nome[50];
    int punteggio = 0;

    // Ottenere il nome dell'utente
    printf("Inserire il proprio nome: ");
    scanf("%s", nome);
    printf("Benvenuto, %s! Iniziamo il gioco.\n\n", nome);

    // Array di domande
    char *domande[] = {
        "Qual è il nome del protagonista di 'Naruto'?",
        "In 'One Piece', quale frutto del diavolo ha mangiato Monkey D. Rufy?",
        "Qual è il nome dell'anime in cui i personaggi usano delle sfere per catturare creature?"
    };

    // Array di risposte possibili (deve avere 3 risposte per ogni domanda)
    char *risposte[][3] = {
        {"A) Sasuke Uchiha", "B) Naruto Uzumaki", "C) Sakura Haruno"},
        {"A) Gomu Gomu", "B) Mera Mera", "C) Hie Hie"},
        {"A) Digimon", "B) Bakugan", "C) Pokemon"}
    };

    // Array di indici delle risposte corrette
    char risposteCorrette[] = {'B', 'A', 'C'};

    // Numero di domande
    int numeroDomande = sizeof(domande) / sizeof(domande[0]);

    // Ciclo sulle domande
    for (int i = 0; i < numeroDomande; i++) {
        printf("Domanda %d: %s\n", i + 1, domande[i]);
        for (int j = 0; j < 3; j++) {
            printf("%s\n", risposte[i][j]);
        }

        // Ottenere la risposta dell'utente
        char rispostaUtente;
        printf("Inserire la risposta (A/B/C): ");
        scanf(" %c", &rispostaUtente);

        // Valutare la risposta dell'utente
        if (rispostaUtente == risposteCorrette[i]) {
            printf("Risposta corretta!\n");
            punteggio++;
        } else {
            printf("Risposta sbagliata. La risposta corretta era %c.\n", risposteCorrette[i]);
        }
        printf("\n");
    }

    // Mostrare il punteggio finale
    printf("%s, hai totalizzato %d punti su %d.\n", nome, punteggio, numeroDomande);
}

int main() {
    mostraIntroduzione();
    while (1) {
        mostraMenu();
        char scelta = ottieniScelta();
        switch (scelta) {
            case 'A':
            case 'a':
                nuovaPartita();
                break;
            case 'B':
            case 'b':
                printf("Grazie per aver giocato! Arrivederci!\n");
                exit(0); // Esce dal programma
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    }
    return 0;
}
