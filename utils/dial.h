/*
** dial.h for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 10:22:14 2017 BOURDALE Jules
** Last update Fri Nov 10 00:39:28 2017 BOURDALE Jules
*/
#ifndef __DIAL_H__
# define __DIAL_H__

# define SHIP_CONSTRUCTION "construction du vaisseau en cours..."
# define SHIP_CONSTRUCTION_OVER "amelioration du vaisseau termine!\n"
# define SHIP_CONSTRUCTION_FAILED "le vaisseau n'a pas pu etre \
construit par manque de materiaux\n"
# define ONLINE_STATUS "online"
# define OFFLINE_STATUS "offline"
# define WEAPON_ADD "ajout des armes en cours...\n"
# define WEAPON_ADD_FAILED "votre vaisseau a explose quand vous \
avez tente d'ajouter les armes\n"
# define WEAPON_ADD_SUCCESS "les armes on ete ajoutes avec succes!\n"
# define FTL_DRIVE_ADD "ajout du reacteur en cours...\n"
# define FTL_DRIVE_ADD_FAILED "votre vaisseau a explose lorsque \
vous avez pose le reacteur\n"
# define FTL_DRIVE_ADD_SUCCESS "le reacteur a ete ajoute avec succes!\n"
# define NAVIGATION_TOOLS_ADD "ajout des outils de navigations...\n"
# define NAVIGATION_TOOLS_ADD_FAILED "votre vaisseau a explose lorsque \
vous avez pose les outils de navigations\n"
# define NAVIGATION_TOOLS_ADD_SUCCESS "les outils de navigations ont \
ete ajoutes avec succes!\n"
# define CONTAINER_ADD "ajout du container en cours...\n"
# define CONTAINER_ADD_FAILED "votre vaisseau a explose lorsque vous \
avez pose le container\n"
# define CONTAINER_ADD_SUCCESS "le container a ete ajoute avec succes!\n"
# define DRIVE_SYSTEM_CHECK_BEGIN "verification du reacteur en cours...\n"
# define DRIVE_SYSTEM_CHECK_SUCCESS "reacteur OK!\n"
# define DRIVE_SYSTEM_CHECK_FAILED "reacteur hors service!\n"
# define NAVIGATION_TOOLS_SYSTEM_CHECK_BEGIN "verification du systeme \
de navigation en cours...\n"
# define NAVIGATION_TOOLS_SYSTEM_CHECK_SUCCESS "systeme de navigation OK!\n"
# define NAVIGATION_TOOLS_SYSTEM_CHECK_FAILED "systeme de navigation \
hors service!\n"
# define WEAPON_SYSTEM_CHECK_BEGIN "verification du systeme d'armement \
en cours...\n"
# define WEAPON_SYSTEM_CHECK_SUCCESS "systeme d'armement OK!\n"
# define WEAPON_SYSTEM_CHECK_FAILED "systeme d'armement hors service!\n"
# define DRIVE_REPAIR_BEGIN "reparation du reacteur en cours...\n"
# define DRIVE_REPAIR_SUCCESS "reparation termine! systeme reacteur OK!\n"
# define DRIVE_REPAIR_FAILED "les reparations du reacteur ont echoue\n"
# define NAVIGATION_TOOLS_REPAIR_BEGIN "reparation du systeme de \
navigation en cours...\n"
# define NAVIGATION_TOOLS_REPAIR_SUCCESS "reparation termine! systeme de \
navigation OK!\n"
# define NAVIGATION_TOOLS_REPAIR_FAILED "les reparations des outils de \
navigations ont echoue\n"
# define WEAPON_REPAIR_BEGIN "reparation du systeme d'armement en cours...\n"
# define WEAPON_REPAIR_SUCCESS "reparation termine! systeme d'armement OK!\n"
# define WEAPON_REPAIR_FAILED "les reparations du systeme d'armement \
ont echoue\n"
# define PROMPT_GLOBAL "ftl~>"
# define PROMPT_GLOBAL_BAD_COMMAND "[SYSTEM FAILURE] : commande inconnue\n"
# define PROMPT_REPAIR_SYSTEM "repair_system~>"
# define PROMPT_REPAIR_SYSTEM_BAD_CALL "[SYSTEM FAILURE] : commande inconnue\n"
# define PROMPT_REPAIR_SYSTEM_FAILED "[SYSTEM FAILURE] : le lecteur de \
commande est bloque\n"
# define ATTACK_PLAYER_LAUNCH "Systeme d'armement armée! FEU!\n"
# define ATTACK_PLAYER_TOUCHED "BOUM! Ennemi touche!\nVous avez inflige "
# define ATTACK_PLAYER_TOUCHED_END " dégats! \n"
# define ATTACK_ENNEMI_LAUNCH "Un ennemi nous attaque !\n"
# define ATTACK_ENNEMI_EVADE "Youuuu on a esquive le missile!\n"
# define ATTACK_ENNEMI_TOUCHED "L'ennemi nous a touché! Nous avons encaissé "
# define ATTACK_ENNEMI_TOUCHED_END " degats!\n"
# define ATTACK_SYSTEM_NOT_AVAILIBLE "Notre systeme d'armement n'est pas \
disponible!\n"
# define ATTACK_NOT_AVAILIBLE "Prof Chen: Ce n'est pas le moment d'utiliser \
ceci!\n"
# define ATTACK_PLAYER_LOSE_ENERGY "Vous perdez 1 point d'energie lors du \
combat! \n"
# define ATTACK_ENNEMI_KILLED "L'ennemi a explosé sous vos bombes!\n"
# define JUMP_COMMAND_NOT_AVAILIBLE "Prof Chen: Ce n'est pas le moment \
d'utiliser ceci!\n"
# define JUMP_COMMAND_SUCCESS "Saut dans l'hyperespace dans 3.. 2.. 1.. !\n"
# define DISPLAY_SHIP " \
[=====>\n \
[  (    _______\n \
 \\__\\, -'//     `--._\n \
  [_/~||, ------. \\@_\\\\___\n \
  [_) |||()()()       ~[|||>\n \
  [_\\_||`--------'    //\n \
 /  /`-.\\\\_____, --'==(-\n \
[  (\n \
[=====>\n"
# define STATUS_HULL "Armure : "
# define STATUS_WEAPON "\nForce de frappe : "
# define STATUS_DRIVE "\nMoteur : "
# define STATUS_NAVIGATION_TOOLS "\nOutils de navigation : "
# define STATUS_CONTAINER "\nTonnes chargees a bord : "
# define STATUS_SECTOR "\nVous êtes dans le secteur : "

# define DETECT_BONUS_SUCCESS "Analyse du secteur terminé!\n"
# define DETECT_BONUS_NOT_AVAILIBLE "Vous avez déjà analysé ce secteur!\n"

# define QUIT_MESSAGE "Vous quittez la partie!\n"
# define HELP_MESSAGE "Commandes disponibles : \n\tattack\n\tdetect\n\t \
jump\n\tgetbonus\n\trepair_system\n\tcontrol_system\n\tstat\n\tquit\
\n\thelp/?\n"

# define GUI_WINDOW_TITLE "My FTL"
# define GUI_FAIL_LOAD_SDL "Erreur lors de l'initialisation de SDL\n"
# define GUI_FAIL_LOAD_WINDOW "Erreur lors de l'ouverture de la fenetre\n"
# define SECTOR_GUI_TEXT "Secteur AG-Y"
#endif
