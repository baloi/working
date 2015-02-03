/*
//
//  
//  link_list.h
// 
//  
// 
//  By Adrian Galia - 1/27/2015
// 
//  My implementation of linked list in C.
// 
// 
//  HOW TO USE IT
// 
//  Declare a structure that will be contained in one or more linked lists:
// 
//       struct _foo_ {
//           agList_link( _foo_ )    m_linkByData;
//           agList_link( _foo_ )    m_linkByType;
//           int                     m_data; 
//           int                     m_type; 
//       };
// 
//  Declare list variables:   
//       agList_declare( _foo_, m_linkByData )   listByData; 
//       agList_declare( _foo_, m_linkByType )   listByType; 
//    
//  Operations on links:  
//       T * Prev(); 
//       T * Next(); 
//       void Unlink();
//       bool IsLinked() const;
//    
//  Operations on lists:  
//       bool Empty() const;
//       void UnlinkAll(); 
//       void DeleteAll(); 
//   
//       T * Head(); 
//       T * Tail(); 
//       T * Prev( T * node); 
//       T * Next(T * node);
//    
//       void InsertHead( T * node );
//       void InsertTail( T * node ); 
//       void InsertBefore( T * node, T * before );
//       void InsertAfter( T  * node, T * after ); 
 */ 

#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

#include "common.h"

////////////////////////////////////////////////////////////////////////////////
//     
//  agListNode structure
// 
////////////////////////////////////////////////////////////////////////////////

typedef struct _list_node_ agListNode;

struct  _list_node_ {
    char *          item;

    void                ( * unlink )        ( void * self );
    bool                ( * is_linked )     ( void * self ); 

    agListNode *    prev;
    agListNode *    next;
};


////////////////////////////////////////////////////////////////////////////////
//
//  agList structure
//
////////////////////////////////////////////////////////////////////////////////

typedef struct _list_ agList;

struct _list_ {
    int             count;

    agListNode *        ( * next )          ( void * self, agListNode * ); 
    agListNode *        ( * prev )          ( void * self, agListNode * ); 
    void                ( * insert_head )   ( void * self, agListNode * );
    void                ( * insert_tail )   ( void * self, agListNode * );
    void                ( * insert_before ) ( void * self, agListNode * node, agListNode * before );
    void                ( * insert_after )  ( void * self, agListNode * node, agListNode * after );
    // int              ( * search )        ( void * self, agListNode * );

    agListNode *    head; 
    agListNode *    tail; 

};

extern      agList *        agList_create();
extern      void            agList_destroy( agList * list ); 
extern      agListNode *    agListNode_create();

#endif
