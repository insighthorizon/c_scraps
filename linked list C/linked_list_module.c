// @licence according to the legislative of united states of me, just kidding, fuck licencing and copyright

// TODO include guard
// TODO everything else aside from typedef and remove entry 
// TODO test it

typedef struct node_t{
	int data;
	struct node_t	*next;
}node_t;


void remove_list_entry(node_t *head, node_t *entry)
{
	// The 'indirect" pointer points to the
	// *address* of the thing we'll update
	
	node_t **indirect = &head;
	
	// Walk the list, looking for the thing that
	// points to the entry we want to remove
	
	while ((*indirect) != entry){
		indirect = &(*indirect)->next;
	}
	
	// ... and just remove it
	*indirect = entry->next;
	
}

