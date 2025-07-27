# Template LaTeX - Rapport de stage

## Table des matières

- [Liens importants](#liens-importants)
- [Motivations](#motivations)
- [Fonctionnalités](#fonctionnalités)
  - [Classe `ensiie-report`](#classe-ensiie-report)
    - [Options](#options)
    - [Macros](#macros)
  - [Paquet `preamble`](#paquet-preamble)
    - [Commande `fileInput`](#commande-fileinput)
    - [Commande `tcbFileInput`](#commande-tcbfileinput)
    - [Environnement `terminalcode`](#environnement-terminalcode)
    - [Commande `inlinegraphics`](#commande-inlinegraphics)
- [Rédaction du rapport](#rédaction-du-rapport)
- [Compatibilité](#compatibilité)
- [Développement](#développement)


## Enregistrer le template

- Aller sur **https://git.iiens.net/lucas2023/iiepp-latex**.
- Sélectionner le dossier `template`.
- Cliquer sur le bouton `Code`.
- Dans la partie *Download directory*, choisir le format de l'archive à télécharger.


## Motivations

Il s'agit d'une proposition de template, inspiré du template de 3A disponible sur le site https://stages.ensiie.fr, pour vous permettre de réaliser simplement votre rapport sans perdre du temps à comprendre certains détails de LaTeX.


## Fonctionnalités

### Classe `ensiie-report`

*Inspiration et reprise de la page de garde du template d'Antoine '**Phoko**' Barbier, disponible à cette adresse : https://gitlab.com/Phokopi/rapport_template.*

Cette classe définit essentiellement des macros, des commandes personnalisées, et le style des pages pour faire un rapport de stage.
La classe de base est `article`, donc les parties du document sont des sections.

#### Options

Des options sont applicables à la classe.

- `language=[fr|en]` | Définition de la langue de votre rapport. Cela ne changera que la langue de la page de garde. Le paquet `babel` n'étant pas utilisé, cela ne changera pas les conventions du document (qui varient surtout pour le français). Langue par défaut : `fr`.
- `year=[1A|2A|3A]` | Définition de l'année de votre stage. Cela changera que l'année indiquée sur la page de garde. Année par défaut : `1A`.
- `enterprise=[|ensIIE|CEA]` | Définition de l'entreprise dans laquelle vous faites votre stage. Cela est purement cosmétique, et cela ajoutera seulement des illustrations sur la page de garde. Option facultative.

**Exemples d'application :**

```latex
\documentclass[language=fr, year=2A, enterprise=CEA]{ensiie-report} % Rapport d'un stage au CEA de 2A en français
\documentclass[language=en, year=3A]{ensiie-report} % Rapport de stage de 3A en anglais
```

#### Macros

Comme indiqués par la présence de `TODO`s dans `main.tex`, vous devez spécifier certaines informations pour afficher proprement la page de garde, l'entête et le pied de page.
Elles sont répertoriées dans la partie `MÉTADONNÉES` du fichier `main.tex`.

Les macros standards sont nécessaires, peu importe le choix de la classe.

```latex
\title{Sujet de stage} % Sujet du stage
\author{Prénom NOM} % Prénom NOM de l'étudiant(e)
\date{Jour1 AA mois1 20XX au jour2 BB mois2 20YY} % Dates du stage
```

Les autres macros sont internes à la classe `ensiie-report` et doivent alors être supprimées (ou commentées) si vous utilisez une autre classe.

```latex
\years{20XX-20YY} % Année scolaire en cours
\logoSchool{img/logo_ensiie.png} % Chemin vers le logo de l'ensIIE (ex : img/logo_ensiie.png)
\logoEnterprise{example-image-a} % Chemin vers le logo de l'entreprise du stage (ex : img/logo_entreprise.png)
\academicSupervisor{Prénom NOM} % Tuteur de stage
\internshipSupervisor{Prénom NOM} % Maître de stage
\internshipEnterprise{Entreprise (Ville, département)} % Lieu du stage
```

### Paquet `preamble`

**Ce paquet est compatible avec n'importe quelle classe.**

Elle (re)définit plusieurs paramètres pour sublimer votre rapport.

L'intérêt du paquet réside essentiellement sur les choix cosmétiques pour assurer la propreté du rapport, ainsi que sur les quelques commandes personnalisées présentes.

#### Commande `fileInput`

> **/!\ La commande fonctionne avec la version 2025 de TeX Live. Si vous avez une erreur en tentant d'utiliser cette commande, référez-vous à la commande [`tcbFileInput`](#commande-tcbfileinput).**

Insertion d'un fichier de code. Il prend en entrée le chemin relatif vers le fichier ainsi que 4 options.
- `language` | Choix du langage du fichier pour avoir la coloration syntaxique associée. Langage par défaut : `text` (aucune coloration syntaxique).
- `logo` | Choix d'une illustration dans la légende. Référez-vous à la liste d'illustrations du paquet [awesome5](https://texlive.mycozy.space/fonts/fontawesome5/doc/fontawesome5.pdf). Logo par défaut : `\faFile`.
- `caption` | Ajout d'une légende du fichier. Légende par défaut : `Légende`.
- `label` | Ajout d'une étiquette pour faire référence au code dans le document avec les commandes `\ref` ou `\autoref`, par exemple. **Convention :** préfixe `lst:` pour faciliter la recherche de l'étiquette. Label par défaut : `lst:todo`.

**Exemple d'utilisation :**

```latex
\fileInput[%
    language=python,
    logo=\faPython,
    caption={Exemple de script Python},
    label=lst:dummy
]{lst/dummy.py}
```

#### Commande `tcbFileInput`

Alternative à la commande [`fileInput`](#commande-fileinput), le principe est le même.

**Exemple d'utilisation :**

```latex
\tcbFileInput{python}{\faPython}{lst/dummy.py}{Exemple de script Python}{lst:dummy}
```

#### Environnement `terminalcode`

Environnement pour illustrer un terminal shell.

**Exemple d'utilisation :**

```text
\begin{terminalcode}
$ echo "Hello world!"
Hello world!
$ sleep 1
$
\end{terminalcode}
```

### Commande `inlinegraphics`

Insertion d'une image à la suite d'un texte. *L'idée est la même que pour les bulles de texte de la série de jeux **Super Mario Galaxy**.*

**Exemple d'utilisation :**

```latex
Ceci est une introduction à \texttt{mpi4py} \inlinegraphics{img/logo_mpi4py.pdf} pour tous.
```

## Rédaction du rapport

Vous devez insérer des métadonnées au début du fichier `main.tex` comme indiqué précédemment.

Le fichier `glossaries.tex` vous permet d'insérer votre glossaire, des mots de vocabulaires, ou des symboles. Le template présente des exemples d'application.

Le fichier `references.bib` vous permet d'ajouter votre bibliographie. Le template présente des exemples d'application.

Je vous suggère la convention suivante pour avoir un code source de votre rapport organisée et propre :
- Le dossier `img` contient toutes les images.
- Le dossier `lst` contient vos listings, c'est-à-dire vos morceaux de code.
- Le dossier `sub` contient des sous-fichiers pour les différentes parties de votre rapport. Libre à vous de les organiser comme vous le souhaitez.
- Le dossier `tikz` contient vos illustrations faites à la main avec TikZ.

## Compatibilité

Ce template est adaptée à la rédaction sur **VSCode**/**VSCodium** (je vous recommande notamment de copier le dossier `.vscode` pour profiter de mes configurations).

Le fichier `.latexmkrc` assure également sa compatibilité sur **Overleaf** (en plus d'être nécessaire sur **VSCode**/**VSCodium** pour gérer proprement le glossaire).

**L'externalisation TikZ ne fonctionne pas sur Overleaf.** Par conséquent, les lignes permettant de l'activer sont commentées dans `main.tex`. Vous pouvez les décommenter si vous travaillez en local et si vous souhaitez profiter de cette fonctionnalité pour gagner du temps de compilation.

Un `Makefile` est également présent si vous développez sur un éditeur de texte depuis le terminal. `make` assure la compilation avec l'outil `latexmk`.

## Développement

Ce template a été réalisé de manière à ce que vous n'ayez pas besoin de toucher aux fichiers `ensiie-report.cls` et `preamble.sty`.

Vous pouvez emprunter le fichier `preamble.sty` tel que conçu pour vos rapports personnels, puisqu'il ne dépend pas la classe `ensiie-report.cls`. **Toutefois, ce paquet n'est pas compatible avec la classe `beamer`.**

Si certains choix cosmétiques vous déplaisent, je vous laisse les modifier si besoin.

Toujours dans un souci de propreté, n'hésitez pas à ajouter vos paquets et commandes personnalisées dans `preamble.sty`.

N'hésitez pas à faire un fork de ce dépôt si vous souhaitez effectuer des pull requests pour améliorer ce template.
