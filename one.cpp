Node *merge (Node *h1,Node *h2)
{
    if(h1==NULL) return(h2);
    if(h2==NULL) return(h1);

    Node* result;
    if(h1->data<h2->data) 
    {
        result=h1;
        result->bottom=merge(h1->bottom,h2);
    }
    else
    {
        result=h2;
        result->bottom=merge(h1,h2->bottom);
    }
    result->next=NULL;
    return result;
}

Node *flatten(Node *root)
{
    if(root==NULL or root->next==NULL)
        return root;

    return merge(root,flatten(root->next));
}