# holds the binary tree implementation and methods for solving problem3
class BinaryTreeNode:
    def __init__(self, value):
        self.value = value
        self.leftChild = None
        self.rightChild = None 

serialization_list = []

def in_order_traversal(root):
    if root is None:
        return
    
    # Traverse the left childs
    in_order_traversal(root.leftChild)
    
    print(root.value, end=" ")
    
    # Traverse the right childs
    in_order_traversal(root.rightChild)

def serialize_helper(root):
    str_value = str(root.value)
    serialization_list.append(str_value)   

def deserialize_helper(serialization_list):
    if serialization_list[0] != "null":
        root = BinaryTreeNode(serialization_list[0])
    else :
        serialization_list.pop(0)
        return None
        
    serialization_list.pop(0)

    root.leftChild = deserialize_helper(serialization_list) 
    
    root.rightChild = deserialize_helper(serialization_list)

    return root
        
def pre_order_traversal(root):
    if root is None:
        print ("null", end=" ")
        serialization_list.append("null")
        return
    
    serialize_helper(root)
    
    print (root.value, end=" ")
    
    pre_order_traversal(root.leftChild)
    
    pre_order_traversal(root.rightChild)
    
if __name__ == "__main__":

    a1=BinaryTreeNode(10)       
    a2=BinaryTreeNode(11)
    a3=BinaryTreeNode(12)
    a4=BinaryTreeNode(13)
    a5=BinaryTreeNode(14)
    a6=BinaryTreeNode(15)
    a7=BinaryTreeNode(16)

    a1.leftChild=a2
    a1.rightChild=a3
    a2.leftChild=a4
    a2.rightChild=a5
    a3.leftChild=a6
    a3.rightChild=a7

    pre_order_traversal(root=a1)
    print(serialization_list)
    new_root = deserialize_helper(serialization_list)
    pre_order_traversal(new_root)
    