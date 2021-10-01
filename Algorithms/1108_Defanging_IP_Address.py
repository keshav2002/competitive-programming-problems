'''
    Problem Statement : 1108. Defanging an IP Address
    Link : https://leetcode.com/problems/defanging-an-ip-address/
    score : accepted
'''
class Solution:
    def defangIPaddr(self, address: str) -> str:
        '''
        takes approximately 32ms
        '''
        address = address.replace('.','[.]')
        return address
    
    def defangIPaddr2(self,address):
        '''
        takes approximately 20ms
        '''
        final = []
        for i in address:
            if i =='.':
                final.append('[.]')
            else:
                final.append(i)
        return ''.join(final)
    
    def defangIPaddr3(self,address):
        '''
        takes approximately 32ms
        '''
        import re
        return re.sub('\.','[.]',address)
    
s = Solution()
s.defangIPaddr('255.100.50.0')
s.defangIPaddr2('255.100.50.0')
s.defangIPaddr3('255.100.50.0')

