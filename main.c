#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (lst && del)
    {
        del(lst->content);
        free(lst);
    }
}

// Function to delete content (for testing)
void delete_content(void *content)
{
    // If content is a dynamically allocated string, free it
    free(content);
}

	int main(void)
	{
		// Create a new node
		t_list *node = malloc(sizeof(t_list));
		if (!node)
		{
			return 1; // Handle malloc failure
		}
		
		// Allocate memory for the content (for example, a string)
		node->content = malloc(20 * sizeof(char));
		char str[20] = "hello hello hello 1";
		node->content = str;

		// Assign some data to the content
		node->next = NULL; // This node does not point to any next node

		
		printf("%s\n", node->content);

		// Test the ft_lstdelone function
		ft_lstdelone(node, delete_content);

		// After deletion, we should not access the node or its content
		// To confirm it was deleted, we could print a message or check for null pointer
		printf("%s\n", node->content);
		printf("Node deleted successfully.\n");

		return 0;
	}
