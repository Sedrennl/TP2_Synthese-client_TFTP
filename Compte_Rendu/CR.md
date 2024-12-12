# Compte rendu, BLARET Julien LABROUSSE Sédrenn
2G1 TD3 TP6 | ENSEA 2024

## TP de Synthèse –  client TFTP

**Objectifs :** Réaliser un client TFTP, à l’aide des RFC et de captures wireshark

## Résumé documentation 
Pour commmencer nous avons beaucoup de documentation à lire, nous allons essayer de récupérer les informations importantes pour nous ci-dessous.

### THE TFTP PROTOCOL
Trivial File Transfer Protocol plus simple
basé su rle protocole UDP

#### Messages définis dans le protocole ou requètes :

- **RRQ (Read Request) :** Demande de lecture d'un fichier.
- **WRQ (Write Request) :** Demande d'écriture d'un fichier.
- **DATA :** Bloc de données à transmettre.
- **ACK (Acknowledgment) :** Accusé de réception pour confirmer la réception d'un bloc.
- **ERROR :** Message d'erreur.

![Figure](photos/fig_Order_of_Headers.jpeg)

*1. Host A sends  a  "WRQ"  to  host  B  with  source=  A's  TID, destination= 69.* 69 car Request 

*2. Host  B  sends  a "ACK" (with block number= 0) to host A with source= B's TID, destination= A's TID.*


Nous sommes à l'adresse du serveur 127.0.0.1 port 69 (soit le localhost)
Comme indiqué dans la photo ci-dessous : 
![Figure](photos/setup_tftpserver.png)



