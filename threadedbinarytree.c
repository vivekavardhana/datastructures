4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
259
260
261
262
263
264
265
266
267
268
269
270
271
272
273
274
275
276
277
278
279
280
281
282
283
284
285
286
287
288
289
290
291
292
293
294
295
296
297
298
299
300
301
302
303
304
305
306
307
308
309
310
311
312
313
314
315
316
317
318
319
320
321
322
323
324
325
326
327
328
329
330
331
332
333
334
335
	
/* C Program to Implement operations in Threaded Binary Search Tree */
 
#include <stdio.h>
#include <stdlib.h>
 
typedef enum {false,true} boolean;
 
struct node *in_succ(struct node *p);
struct node *in_pred(struct node *p);
struct node *insert(struct node *root, int ikey);
struct node *del(struct node *root, int dkey);
struct node *case_a(struct node *root, struct node *par,struct node *ptr);
struct node *case_b(struct node *root,struct node *par,struct node *ptr);
struct node *case_c(struct node *root, struct node *par,struct node *ptr);
 
void inorder( struct node *root);
void preorder( struct node *root);
 
struct node
{
        struct node *left;
        boolean lthread;
        int info;
        boolean rthread;
        struct node *right;
};
 
int main( )
{
        int choice,num;
        struct node *root=NULL;
 
        while(1)
        {
                printf("\n");
                printf("1.Insert\n");
                printf("2.Delete\n");
                printf("3.Inorder Traversal\n");
                printf("4.Preorder Traversal\n");
                printf("5.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);
 
                switch(choice)
                {
                 case 1:
                        printf("\nEnter the number to be inserted : ");
                        scanf("%d",&num);
                        root = insert(root,num);
                        break;
 
                 case 2:
                        printf("\nEnter the number to be deleted : ");
                        scanf("%d",&num);
                        root = del(root,num);
                        break;
 
                 case 3:
                        inorder(root);
                        break;
 
                 case 4:
                        preorder(root);
                        break;
 
                 case 5:
                         exit(1);
 
                 default:
                        printf("\nWrong choice\n");
                }/*End of switch */
        }/*End of while */
 
        return 0;
 
}/*End of main( )*/
 
struct node *insert(struct node *root, int ikey)
{
        struct node *tmp,*par,*ptr;
 
        int found=0;
 
        ptr = root;
        par = NULL;
 
        while( ptr!=NULL )
        {
                if( ikey == ptr->info)
                {
                        found =1;
                        break;
                }
                par = ptr;
                if(ikey < ptr->info)
                {
                        if(ptr->lthread == false)
                                ptr = ptr->left;
                        else
                                break;
                }
                else
                {
                        if(ptr->rthread == false)
                                ptr = ptr->right;
                        else
                                break;
                }
        }
 
        if(found)
                printf("\nDuplicate key");
        else
        {
 
                tmp=(struct node *)malloc(sizeof(struct node));
                tmp->info=ikey;
                tmp->lthread = true;
                tmp->rthread = true;
                if(par==NULL)
                {
                        root=tmp;
                        tmp->left=NULL;
                        tmp->right=NULL;
                }
                else if( ikey < par->info )
                {
                        tmp->left=par->left;
                        tmp->right=par;
                        par->lthread=false;
                        par->left=tmp;
                }
                else
                {
                        tmp->left=par;
                        tmp->right=par->right;
                        par->rthread=false;
                        par->right=tmp;
                }
        }
        return root;
}/*End of insert( )*/
 
struct node *del(struct node *root, int dkey)
{
        struct node *par,*ptr;
 
        int found=0;
 
        ptr = root;
        par = NULL;
 
        while( ptr!=NULL)
        {
                if( dkey == ptr->info)
                {
                        found =1;
                        break;
                }
                par = ptr;
                if(dkey < ptr->info)
                {
                        if(ptr->lthread == false)
                                ptr = ptr->left;
                        else
                                break;
                }
                else
                {
                        if(ptr->rthread == false)
                                ptr = ptr->right;
                        else
                                break;
                }
        }
 
        if(found==0)
                printf("\ndkey not present in tree");
        else if(ptr->lthread==false && ptr->rthread==false)/*2 children*/
                root = case_c(root,par,ptr);
        else if(ptr->lthread==false )/*only left child*/
        root = case_b(root, par,ptr);
        else if(ptr->rthread==false)/*only right child*/
        root = case_b(root, par,ptr);
        else /*no child*/
                root = case_a(root,par,ptr);
        return root;
}/*End of del( )*/
 
struct node *case_a(struct node *root, struct node *par,struct node *ptr )
{
        if(par==NULL) /*root node to be deleted*/
                root=NULL;
        else if(ptr==par->left)
        {
                par->lthread=true;
                par->left=ptr->left;
        }
        else
        {
                par->rthread=true;
                par->right=ptr->right;
        }
        free(ptr);
        return root;
}/*End of case_a( )*/
 
struct node *case_b(struct node *root,struct node *par,struct node *ptr)
{
        struct node *child,*s,*p;
 
        /*Initialize child*/
        if(ptr->lthread==false) /*node to be deleted has left child */
                child=ptr->left;
        else                /*node to be deleted has right child */
                child=ptr->right;
 
 
        if(par==NULL )   /*node to be deleted is root node*/
                root=child;
        else if( ptr==par->left) /*node is left child of its parent*/
                par->left=child;
        else                     /*node is right child of its parent*/
                par->right=child;
 
        s=in_succ(ptr);
        p=in_pred(ptr);
 
        if(ptr->lthread==false) /*if ptr has left subtree */
                        p->right=s;
        else
        {
                if(ptr->rthread==false) /*if ptr has right subtree*/
                        s->left=p;
        }
 
        free(ptr);
        return root;
}/*End of case_b( )*/
 
struct node *case_c(struct node *root, struct node *par,struct node *ptr)
{
        struct node *succ,*parsucc;
 
        /*Find inorder successor and its parent*/
        parsucc = ptr;
        succ = ptr->right;
        while(succ->left!=NULL)
        {
                parsucc = succ;
                succ = succ->left;
        }
 
        ptr->info = succ->info;
 
        if(succ->lthread==true && succ->rthread==true)
                root = case_a(root, parsucc,succ);
        else
                root = case_b(root, parsucc,succ);
        return root;
}/*End of case_c( )*/
 
struct node *in_succ(struct node *ptr)
{
        if(ptr->rthread==true)
                return ptr->right;
        else
        {
                ptr=ptr->right;
                while(ptr->lthread==false)
                        ptr=ptr->left;
                return ptr;
        }
}/*End of in_succ( )*/
 
struct node *in_pred(struct node *ptr)
{
        if(ptr->lthread==true)
                return ptr->left;
        else
        {
                ptr=ptr->left;
                while(ptr->rthread==false)
                        ptr=ptr->right;
                return ptr;
        }
}/*End of in_pred( )*/
 
void inorder( struct node *root)
{
        struct node *ptr;
        if(root == NULL )
        {
                printf("Tree is empty");
                return;
        }
 
        ptr=root;
        /*Find the leftmost node */
        while(ptr->lthread==false)
                ptr=ptr->left;
 
        while( ptr!=NULL )
        {
                printf("%d ",ptr->info);
                ptr=in_succ(ptr);
        }
}/*End of inorder( )*/
 
void preorder(struct node *root )
{
        struct node *ptr;
        if(root==NULL)
        {
                printf("Tree is empty");
                return;
        }
        ptr=root;
 
        while(ptr!=NULL)
        {
                printf("%d ",ptr->info);
                if(ptr->lthread==false)
                        ptr=ptr->left;
                else if(ptr->rthread==false)
                        ptr=ptr->right;
                else
                {
                        while(ptr!=NULL && ptr->rthread==true)
                                ptr=ptr->right;
                        if(ptr!=NULL)
                                ptr=ptr->right;
                }
        }
}/*End of preorder( )*/
