/**
 * section: Tree
 * synopsis: Navigates a tree to print element names
 * purpose: Parse a file to a tree, use xmlDocGetRootElement() to
 *          get the root element, then walk the document and print
 *          all the element name in document order.
 * usage: tree1 filename_or_URL
 * test: tree1 test2.xml > tree1.tmp ; diff tree1.tmp tree1.res ; rm tree1.tmp
 * author: Dodji Seketeli
 * copy: see Copyright for the status of this software.
 */
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>


/**
 * print_element_names:
 * @a_node: the initial xml node to consider.
 *
 * Prints the names of the all the xml elements
 * with all attributes and the values
 * that are siblings or children of a given xml node.
 */
static void
print_element_names(xmlNode * a_node)
{
    xmlNode *cur_node = NULL;
    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
    
        /* Knoten ausgeben */
        if (cur_node->type == XML_ELEMENT_NODE) {
            printf("Knotenbezeichnung: %s\n", cur_node->name);
            
            xmlAttr *cur_attr = NULL;
            for (cur_attr = cur_node->properties; cur_attr; cur_attr = cur_attr->next) {
            
                printf("  Attributname: %s\n", cur_attr->name );
                printf("  Attributwert: %s\n", cur_attr->children->content );
                
            }
            
        }
    
        print_element_names(cur_node->children);
    }
}

/**
 * Simple example to parse a file called "file.xml", 
 * walk down the DOM, and print the name of the 
 * xml elements nodes.
 */
int
libxml_tree1(void)
{

    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;
    /*
     * this initialize the library and check potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION

    /*parse the file and get the DOM */
    doc = xmlParseFile("cybol.xml");
    if (doc == NULL) {
        printf("error: could not parse file file.xml\n");
    }

    /*Get the root element node */
    root_element = xmlDocGetRootElement(doc);
    print_element_names(root_element);

    /*free the document */
    xmlFreeDoc(doc);

    /*
     *Free the global variables that may
     *have been allocated by the parser.
     */
    xmlCleanupParser();
    return 0;
}
