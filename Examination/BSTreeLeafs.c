jag valde att skiva en rekursiv gensoms�kning d� jag hade en snarlik funktion tidigare som var numberOfNodes
countLeaf kommer att s�ka fr�n root, om ingen root finns s� returnar funktionen 0. sen kollar den om nuvarande
noden har barn, har den det s� s�ker den h�ger sida f�rst rekursivt, sedan v�nstra sida.

int countLeaf(BSTree tree)
{
	if (tree)//medans tr�det finns, basfall.
	{
		if (tree->right == NULL && tree->left == NULL) //om noden vi �r p� �r ett l�vnode, returna 1.
		{
			return 1;
		}
		else
		{
       /*om noden inte var ett l�vnode,
       rekursivt k�r funktionen men kollar h�ger sida av noden
       sedan v�nster sida och adderar antal l�vNoder (return 0 f�r noder med barn)*/
			return countLeaf(tree->right) + countLeaf(tree->left);
		}
	}
	else
	{
		return 0;
	}
}
