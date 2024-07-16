# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        def find_path(node, value, path):
            #make sure the node is not empty
            if node is None:
                return False
            #value found return successfully
            if node.val == value:
                return True
            #start searching left if there is a left node
            if (node.left):
                #assume we will have a left path
                path.append('L')
                #recursively search for the node starting by the left node
                if find_path(node.left, value, path):
                    return True
                path.pop()
            #start searching right if there is a right node
            if (node.right):
                path.append('R')
                if find_path(node.right, value, path):
                    return True
                path.pop()
            #it is not present neiher left nor right, return false
            return False
        #get the path from root to startValue and from root to destValue
        path_root_to_s = []
        path_root_to_t = []
        find_path(root, startValue,path_root_to_s)
        find_path(root, destValue, path_root_to_t)
        count = 0
        #loop over the found path from root to startValue and search for the common path until a difference is detected then stop
        for step in path_root_to_s:
            print("count is " + str(count))
            if count < len(path_root_to_t):
                if (path_root_to_t[count]) and (step == path_root_to_t[count]):
                    path_root_to_t[count] = '-' #replace the value by a special character to be removed later
                    path_root_to_s[count] = '-'
                else:
                    break
            else:
                break
            count = count + 1
        count = 0
        #reverse any move in the first path to UP
        for step in path_root_to_s:
            if step == 'L' or  step == 'R':
                path_root_to_s[count] = 'U'
            count = count+1
        #append and remove the special characters
        path1 = [i for i in path_root_to_s if i != '-']
        path2 = [i for i in path_root_to_t if i != '-']
        final_path = "".join(path1+path2)
        return str(final_path)
