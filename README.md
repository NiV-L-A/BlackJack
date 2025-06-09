# Blackjack.c
Una implementazione grafica e completamente locale del gioco d'azzardo **BlackJack** scritto <ins>interamente</ins> in **C** (con l'aggiunta di GTK3 per l'interfaccia grafica) da **Domtastick** e **NiV-L-A**!

## Funzionalità del gioco
- Sistema di login
- Possibilità di creare più account locali 
- Storico partite contenente dettagli su quale utente abbia giocato, il resoconto della partita, la quantità di crediti scommessa ed il modo in cui la vittoria/sconfitta abbia influenzato il bilancio
- Statistiche individuali per utente contenente il numero di partite giocate, il tasso di vittoria e il bilancio attuale
- Sistema di "top-up" virtuale per aggiungere crediti al proprio bilancio
- Interfaccia completamente grafica!
- Può runnare su un tostapane!
- [Gambling](https://tenor.com/view/when-the-money-fast-money-gif-18043142)!!!!! 


## Istruzioni su come buildare il progetto
Al momento è compatibile <ins>solo con Linux</ins>.   
È **possibile** modificare il codice per compilare una versione funzionante anche su **Windows** ma è al di fuori dallo scopo del progetto (**per ora**!!).

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
gcc ./main.c -rdynamic -Wno-format -Wno-deprecated-declarations -Wno-format-security `pkg-config --cflags gtk+-3.0` -o ./Blackjack `pkg-config --libs gtk+-3.0`
```
</details>

<details>
  <summary><strong>Istruzioni per altre distro:</strong></summary> 
 
Malgrado non abbia avuto tempo di testare il processo di building su altre distro, non dovrebbero esserci problemi a buildare il progetto.
Basta solo rimpiazzare la sintassi di `apt` con quella del package manager usato dalla vostra distro (il nome dei pacchetti potrebbe variare leggermente in base ad essa).

</details>
