# FluxInfo

## Principe 

Le principe de FluxInfo est de pouvoir gérer ses propres flux RSS.
L'utilisateur peut donc ajouter ou supprimer des flux RSS en copiant le lien de celui-ci dans l'application.
Ensuite un parser permettra de récupérer les articles de ce flux RSS afin de les afficher sur la page d'accueil.

## Plateforme

Cette application est développée pour être lancée sur un SailFish OS.

## Fonctionnement

Quand l'application est lancée, l'utilisateur arrive sur une page avec une Silica ListView permettant d'afficher les articles de ses flux RSS.
Il peut ensuite aller dans le PullDownMenu pour aller sur la page de ses flux RSS où il trouvera une seconde Silica ListView.
L'utilisateur peut ajouter un flux en passant par le PullDownMenu.

Lorsqu'il clique sur un flux ou un article il peut voir le détail de celui-ci.
Pour les flux il peut changer le lien et le titre du flux. Les modifications seront automatiquement prisent en compte.
Il est aussi possible de supprimer un flux en utilisant le PullDownMenu.

## Persistance

Nous avons décidé de sauvegarder les données dans le téléphone avec un format JSON.
La persistance n'est pas encore fonctionnelle.

## Parser RSS
En cours de développement...
