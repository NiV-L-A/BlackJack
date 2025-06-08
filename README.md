# Blackjack.c
Una implementazione grafica e completamente locale del gioco d'azzardo BlackJack scritto **interamente** in C (con l'aggiunta di GTK3 per l'interfaccia grafica) da **Domtastick** e **NiV-L-A**!

## Istruzioni su come buildare il progetto
Al momento e' compatibile <ins>solo con Linux</ins>.   
E' **possibile** modificare il codice per compilare una versione funzionante anche su **Windows** ma e' al di fuori dallo scopo del progetto (**per ora**!!).

 <details>
   <summary><strong>Istruzioni per Ubuntu/Debian e derivati:</strong></summary> 
   
<p>Assicurarsi di installare le development library di GTK:</p>

```
sudo apt install libgtk-3-dev -y
```

Una volta istallate le librerie necessarie, assicuratevi di avere istallato l'utility pkg config (a meno che non vogliate inserire manualmente come flag il directory delle librerie!):
```sh 
sudo apt update
sudo apt install pkg-config -y
```

Aprire un'istanza del vostro terminale di scelta e navigare nella cartella principale in cui e' contenuto il codice sorgente per poi runnare il seguente comando per compilare il progetto:
```sh 
gcc ./main.c -rdynamic `pkg-config --cflags gtk+-3.0` -o Blackjack `pkg-config --libs gtk+-3.0`
```
</details>

<details>
  <summary><strong>Istruzioni per altre distro:</strong></summary>

Malgrado non abbia avuto tempo di testare il processo di building su altre distro, non dovrebbero esserci problemi a buildare il progetto.
Basta solo rimpiazzare la sintassi di `apt` con quella del package manager usato dalla vostra distro (il nome dei pacchetti potrebbe variare leggermente in base alla distro)

</details>
