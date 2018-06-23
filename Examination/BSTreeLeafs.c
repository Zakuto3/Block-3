jag valde att skiva en rekursiv gensomsökning då jag hade en snarlik funktion tidigare som var numberOfNodes
countLeaf kommer att söka från root, om ingen root finns så returnar funktionen 0. sen kollar den om nuvarande
noden har barn, har den det så söker den höger sida först rekursivt, sedan vänstra sida.

int countLeaf(BSTree tree)
{
	if (tree)//medans trädet finns, basfall.
	{
		if (tree->right == NULL && tree->left == NULL) //om noden vi är på är ett lövnode, returna 1.
		{
			return 1;
		}
		else
		{
       /*om noden inte var ett lövnode,
       rekursivt kör funktionen men kollar höger sida av noden
       sedan vänster sida och adderar antal lövNoder (return 0 för noder med barn)*/
			return countLeaf(tree->right) + countLeaf(tree->left);
		}
	}
	else
	{
		return 0;
	}
}
