#include <stdio.h>
#include <stdlib.h>

// le projet finale du module algorithmique et complexitée 
// Abdelli Abdelmoumen 
// gr=03 

typedef struct node* tree;// cette instruction  permet de definir 
// pointer de type node 
typedef struct node {
    int value;
    tree left, right;
} node;
typedef struct Queue {// la definition du pile pour utiliser a l afficahage 
    node* data;
    struct Queue* next;
} Queue;

tree createnode(int v) {// une fonction pour la creation de nodes dans l arbre binaire 
    tree x = malloc(sizeof(node));
    if (x == NULL) { 
        printf("allocation failed \n");
         exit(1); 
        }
    x->value = v; 
    x->left = NULL;
    x->right = NULL;
    return x; 
}
Queue* newQueue(node* v) {
    // la creation du queue
    Queue* P;
    P = (Queue*)malloc(sizeof(Queue));
    P->data = v;
    P->next = P;
    return P;
}

void enfiler(Queue** file, node* v) {
    Queue* P;     // function pour enfiler 
    P = newQueue(v);

    if (*file != NULL) {
        P->next = (*file)->next;
        (*file)->next = P;
    }
    *file = P;
}


node* defiler(Queue** file) {
    Queue* temp;      // function pour defiler 
    node* N = NULL;
    if (*file != NULL) {
        temp = (*file)->next;
        if (temp == *file)
            *file = NULL;
        else
            (*file)->next = temp->next;
        N = temp->data;
        free(temp);
    }
    return N;
}
node* maximum(node* racine)
 {
    node* temp;
    if(racine==NULL) 
      return NULL;

    temp=racine;
    while(temp->right!=NULL)
      temp=temp->right;
   return temp;
 }
 
 node* minimum(node* racine)
 {
    node* temp;
    if(racine==NULL)
      return NULL;

    temp=racine;
    while(temp->left!=NULL)
      temp=temp->left;
   return temp;
 }

void insertnode(node**root, int val) {
    node* n, * tmp;//la creation de n type node est pour creé un node qui porte la valeur de type int val avec l appel
    //du fontion createnode et le tmp pointe sur la  racine dans le point root pour assurer de pas perdre la racine d
    //arbre

    n = createnode(val);
    if (*root == NULL) {//dans le cas de l arbre est  vide on place directement le node au racine
        *root = n;
        return;
    }
      tmp =*root;// en utilisent tmp pour deplacer sur l arbre dans la gauche et la droite et il pointe dans la racine 
    // d arbre le root le root reste toujours fixée 
    while (1) {//une boucle infini pour toujours reboucler a chaque itération çi on na pas placer le node 
    //on c est bien dans les arbres binaires que çi la donnée est sup de la racine on vas a droite  çi le contraire 
    // on vas a gauche 
        if (n->value < tmp->value) {  
            if (tmp->left == NULL) {
                tmp->left = n;
                break;
            } else {
                tmp = tmp->left;
            }
        } else {  
            if (tmp->right == NULL) {
                tmp->right = n;
                break;
            } else {
                tmp = tmp->right;
            }
        }
    }
}

node*searchnode(node*root,int v){ 

    if(root==NULL){
        return NULL;//çi l arbre est vide on va retourner null 
    }
    if(v==root->value){
        return root; // çi la valeur chercher est egale a la racine on retourne la racine
    }
    else if(v<root->value) {
        return searchnode(root->left,v);// çi la valeur rechercher inf de racine on vas a la gauche et chaque fois
        // çi on ne trouve pas dans un node on fait un apelle recursiive pour trouver la valeur 
    }
    else
    return searchnode(root->right,v);//çi toutes les conditions précedente ne fonctionne pas bas la valeur donc dans
    // la droite 
}

node* deleteNode(node* racine, int v) {
    if (racine == NULL)
        return racine;// teste pour connais l arbre est vide ou pas 

    if(v==racine->value)
      {  // Cas 1 : Le nodee  supprimer est une feuille donc ya pas de fils droite et gauche  
            if (racine->left == NULL && racine->right == NULL) {
                free(racine);
                racine = NULL; // la valeur supprimer en remplace avec null
            }
            // Cas 2 : Le node  supprimer a un seul fils (droit ou gauche)
            else if (racine->left == NULL) {
                node* temp = racine;// le role du tmp est pour sauvgarder la valeur du racine que en vas 
                                     // supprimer plus les libirer 
                racine = racine->right;// en fait une liison avec le node precedent de node quand en vas supprimer
                                        // avec le node aprées la valeur supprimer pour n est pas perdre le node 
                free(temp);
            } else if (racine->right == NULL) { // les mémes opération pour la droite  
               node* temp = racine;
                racine = racine->left;
                free(temp);
            }
            // Cas 3 : Le noud  supprimer a deux fils
            // dans ce cas en utilise les deux fonction max ,min pour assurer que  l arbre reste arbre binaire de recherche
            // en veux dire en prends le min c est la valeur cherher est dans la droite et le min devient le node pére 
            // pour que l arbre reste bst 
            else {
                node* temp = minimum(racine->right);// sauvgarder la valeur min dans le temp
                racine->value = temp->value;// donner  la valeur du temp a le node pére 
                racine->right = deleteNode(racine->right, temp->value); // appelle rec pour la supprision 
            }
      }
        else if (v < racine->value)// çi la valeur de la racine n egale pas a la valeur chercher donc inf a gauche
                // sup a droite 
               racine->left = deleteNode(racine->left, v);// apelle rec pour chercher dans la gauche 
             else
               racine->right = deleteNode(racine->right, v);// apelle rec pour chercher dans la droite

     return racine;
}
void printByLevel(node* racine) {
    if (racine == NULL) {
        return; // Si larbre est vide on ne fait rien
    }

    Queue* q = NULL; // File pour stocker les node
    enfiler(&q, racine); // Ajouter la racine à la file
    enfiler(&q, NULL);   // Marqueur de fin de niveau (NULL)

    while (q != NULL) {
        node* toPrint = defiler(&q);

        if (toPrint == NULL) {
            printf("\n"); // Sauter  la ligne pour marquer la fin du niveau

            // Si la file n est pas vide et ajouter un autre marqueur de fin de niveau
            if (q != NULL) {
                enfiler(&q, NULL);
            }
        } else {
            printf("%d ", toPrint->value);

            // Ajouter les enfant gauche et droite  la file
            if (toPrint->left != NULL) {
                enfiler(&q, toPrint->left);
            }
            if (toPrint->right != NULL) {
                enfiler(&q, toPrint->right);
            }
        }
    }
}
int main() {
    int choix, valeur;
    node* racine = NULL;
    node* resultat = NULL;
    int continuer = 1; // Variable pour controler la boucle

    while (continuer) {
        printf("\n--- Menu Principal ---\n");
        printf("1. Inserer une valeur\n");
        printf("2. Afficher l'arbre par niveau\n");
        printf("3. Rechercher une valeur\n");
        printf("4. Supprimer une valeur\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: 
                printf("Entrez la valeur a inserer: ");
                scanf("%d", &valeur);
                insertnode(&racine, valeur);
                printf("Valeur %d inseree.\n", valeur);
                break;

            case 2: 
                printf("L'arbre par niveau:\n");
                printByLevel(racine);
                printf("\n");
                break;

            case 3: 
                printf("Entrez la valeur a rechercher: ");
                scanf("%d", &valeur);
                resultat = searchnode(racine, valeur);
                if (resultat != NULL) {
                    printf("Valeur trouvee: %d\n", resultat->value);
                } else {
                    printf("Valeur non trouvee dans l'arbre.\n");
                }
                break;

            case 4: 
                printf("Entrez la valeur a supprimer: ");
                scanf("%d", &valeur);
                racine = deleteNode(racine, valeur);
                printf("Valeur %d supprimee.\n", valeur);
                break;

            case 5: 
                printf("Au revoir !\n");
                continuer = 0; 
                break;

            default: 
                printf("Choix invalide, veuillez reessayer.\n");
        }
    }

    return 0;
}




 

