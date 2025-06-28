# Blackjack.c
Una implementazione grafica e completamente locale del gioco d'azzardo **BlackJack** scritto <ins>interamente</ins> in **C** (con l'aggiunta di GTK3 per l'interfaccia grafica) da **Domtastick** e **NiV-L-A**!

## Funzionalità del gioco
- Sistema di login
- Possibilità di creare più account locali 
- Storico delle partite giocate dall'utente attualmente loggato assieme al loro resoconto (Risultato, crediti persi/guadagnati)!
- Statistiche individuali per utente contenenti il numero di partite giocate, il tasso di vittoria, il numero di vittorie e il bilancio attuale
- Sistema di "top-up" virtuale per aggiungere crediti al proprio bilancio
- Sistema di difficolta` 
- Interfaccia completamente grafica!
- Può runnare su un tostapane!
- [Gambling](https://tenor.com/view/when-the-money-fast-money-gif-18043142)!!!!! 


## Istruzioni su come buildare il progetto
Al momento è compatibile <ins>solo con Linux</ins>.   
È **possibile** modificare il codice per compilare una versione funzionante anche su **Windows**, ma ciò è al di fuori dallo scopo del progetto (**per ora**!!).

 <details>
   <summary><strong>Istruzioni per Ubuntu/Debian e derivati:</strong></summary> 
   
Assicuratevi di installare le librerie di sviluppo di GTK:

```
sudo apt install libgtk-3-dev -y
```

Una volta installate le librerie necessarie, assicuratevi di avere installato l'utility pkg-config (a meno che non vogliate inserire manualmente come flag il directory delle librerie!):
```sh 
sudo apt update
sudo apt install pkg-config -y
```

Si consiglia l'uso di gcc per compilare il progetto. La stragrande maggioranza delle distribuzioni dovrebbe già averlo come parte di una suite di build tools; ma se per qualche motivo dovesse mancare, potete installarlo con:
```sh
sudo apt install gcc
```

Aprite un'istanza del vostro terminale di scelta e navigate nella cartella principale in cui è contenuto il codice sorgente. In seguito runnate il seguente comando per compilare il progetto:
```sh 
gcc -Wno-format -Wno-deprecated-declarations -Wno-format-security -Wno-discarded-qualifiers -rdynamic $(pkg-config --cflags gtk+-3.0) -o BlackJack main.c Banco.c Giocatore.c GestioneStoricoPartite.c GestioneUtenti.c GUI/bin/InterfacciaGrafica.c Globali.c GUI/bin/GestioneGraficaPartita.c $(pkg-config --libs gtk+-3.0)

```
</details>

<details>
  <summary><strong>Istruzioni per altre distro:</strong></summary> 
 
Malgrado non abbia avuto tempo di testare il processo di building su altre distro, non dovrebbero esserci problemi a farlo.
Basta solo rimpiazzare la sintassi di `apt` con quella del package manager usato dalla vostra distro (il nome dei pacchetti potrebbe variare leggermente in base ad essa).

</details> 

## Troubleshooting basilare
<details>
  <summary><strong>Il gioco non si avvia!</strong></summary> 
  
Per prima cosa assicuratevi che l'eseguibile del gioco abbia i permessi di esecuzione!
Per farlo basta navigare nella cartella sorgente del gioco con il vostro terminale e scrivere il seguente comando:
 ```sh
 ls -l ./BlackJack
 ```
In caso dovessero mancare, potete darglieli con il seguente comando:
```sh
sudo chmod +x BlackJack
```
### Continua a non andare!
Se anche dopo avergli dato i permessi di esecuzione non dovesse comunque funzionare, potrebbe essere un'errore di ownership. 
Il vostro account utente potrebbe non avere il possesso del file e quindi non può runnarlo. In tal caso, usate il seguente comando per dare al vostro utente il possesso del file:
```sh
sudo chown <NomeSistema>:<NomeSistema> BlackJack
```
Sostituite `<NomeSistema>` col nome dell'utente nel quale siete loggati.

Inoltre, tenete conto del fatto che le risorse del gioco **NON** sono embedded! Ciò significa che se doveste provare ad avviarlo spostato l'eseguibile in una cartella diversa da quella del codice sorgente esso **NON** funzionerà!
</details>
<details>
 <summary><strong>Mancano delle texture!</strong></summary> 
 
Come prima cosa **assicuratevi** che l'eseguibile del gioco sia all'interno della cartella con il codice sorgente!
Se poi dovessero mancare delle texture come quelle del menù principale o delle carte, la colpa ricarde sicuramente su uno di questi due fattori:
- **L'eseguibile non ha i permessi di lettura** (Più probabile)
- **L'utente non possiede i directory contenenti le immagini o le immagini stesse** (Meno probabile)

Nel **primo caso**, usate il seguente comando per dare all'eseguibile i permessi di lettura:
```sh
sudo chmod +r BlackJack
```
Nel **secondo caso** cercate istruzioni relative alla vostra distro su come prendere possesso in maniera ricorsiva di più directory.
</details>
<details>
<summary><strong>Le partite o gli utenti non si salvano!</strong></summary>

Come prima cosa controllate che i loro relativi file siano stati creati correttamente navigando nella cartella del codice sorgente ed andando in `File`.
Se avete già avviato il gioco in passato, dovreste trovare due file all'interno di quella cartella:
- **StoricoPartite**
- **Utenti**

Se uno dei due dovesse mancare ed il gioco non riesca a ricrearlo, potrebbero mancargli i permessi di **scrittura**. Lo stesso si applica nel caso in cui i file siano presenti ma le funzionalità di registrazione utenti e storico partite non dovessero comunque funzionare.

Potete dare i permessi di scrittura all'eseguibile navigando nella cartella del codice sorgente in cui è contenuto e runnando il seguente comando:
```sh
sudo chmod +w BlackJack
```
</details>
