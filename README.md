## Ivotek_Robot
Libreria “robotica” per Ivotek – Ivotek Robot Library

## Descrizione
Questo repository raccoglie la libreria **Ivotek_Robot**: un insieme di classi C++ (con file `.h` e `.cpp`) e configurazioni (es. `Config.h`) pensati per il controllo di un robot sviluppato da Ivotek.
Fornisce funzionalità di basso livello per sensori, attuatori, controllo motori, interfacce di configurazione, ed è pensata per progetti di robotica embedded.

## Contenuto del repository
- `Ivotek_Robot.h` e `Ivotek_Robot.cpp`: la classe principale della libreria, che incapsula l’hardware e le logiche base del robot.
- `Config.h`: file di configurazione per definire parametri hardware, pin, costanti, ecc.
- `examples/`: esempi pratici di utilizzo della libreria.
- `keywords.txt`: supporto per l’integrazione con ambienti di sviluppo (es. Arduino IDE).
- `README.md`: questo file.

## Installazione
1. Clona questo repository:
   ```bash
   git clone https://github.com/ivotek/Ivotek_Robot.git
````

2. Copia la cartella nella directory delle librerie del tuo ambiente di sviluppo (es. `libraries/` per Arduino).
3. Includi la libreria nel tuo progetto:

   ```cpp
   #include "Ivotek_Robot.h"
   ```
4. Configura il file `Config.h` in base al tuo hardware (pin, motori, sensori, ecc.).
5. Compila ed esegui uno degli esempi nella cartella `examples/`.

## Esempio base

```cpp
#include <Ivotek_Robot.h>

Ivotek_Robot explorer;

void setup() {
  explorer.initialization("explorer");
}

void loop() {

  explorer.forwards(100, 100);

}
```

> ⚠️ Gli esempi nella cartella `examples/` mostrano casi reali di utilizzo: movimento, lettura sensori, comportamento condizionale, ecc.

## Risorse utili

* Commenti all’interno del codice per comprendere il funzionamento delle funzioni.
* Esempi pratici nella cartella `examples/`.
* `keywords.txt`: supporto per evidenziazione sintassi in IDE compatibili.

## Contribuire

I contributi sono benvenuti!

1. Effettua il fork del repository
2. Crea un branch per la tua modifica (`feature/nome-funzionalità`)
3. Fai una Pull Request descrivendo cosa hai modificato
4. Assicurati che il codice sia chiaro e commentato

## Licenza

*(Da definire: MIT, GPL-3.0 o altra licenza open source consigliata)*
Inserire qui i dettagli della licenza una volta scelta.

## Contatti

Per dubbi, suggerimenti o collaborazioni, contatta il team di Ivotek oppure apri una *Issue* su GitHub.
ivotek@gmail.com
