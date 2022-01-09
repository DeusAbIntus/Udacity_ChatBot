#include "graphedge.h"
#include "graphnode.h"
#include <memory>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.emplace_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) // old code - void GraphNode::AddEdgeToChildNode(GraphEdge* edge)
{
    _childEdges.emplace_back(std::move(edge)); // old code - _childEdges.push_back(edge)
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot); // old code - _chatBot = chatbot
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    // old code - (_chatBot = nullptr; // invalidate pointer at source)
    // chabot pointer no longer needs to be invalidated since we are moving the entire _chatbot pointer to the new node
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return (_childEdges[index]).get();

    ////
    //// EOF STUDENT CODE
}