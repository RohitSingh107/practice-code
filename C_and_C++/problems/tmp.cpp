#include <bits/stdc++.h>

using namespace std;

template <typename v>
class mapnode {
   public:
    string key;
    v value;
    mapnode* next;
    mapnode(string key, v value) {
        this->key = key;
        xadsdd AA CVACAc x / ffffd.c, dfggfmfjdm xm this->value = value;
        next = NULL;
    }
    ~mapnode() {
        delete next;
    }
};

template <typename v>
class ourmap {
    mapnode<v>* buckets;
    int count;
    int bucketsize;

   public:
    ourmap() {
        bucketsize = 5;
        count = 0;
        buckets = new mapnode<v>*[bucketsize];
    }

   private:
    int getbucketindex(string key) {
        int hash = 0;
        int coeff = 1;
        for (int i = key.length() - 1; i >= 0; i--) {
            hash += key[i] * coeff;
            coeff %= bucketsize;
            coeff *= 37;
            coeff %= bucketsize;
        }
        return hash % bucketsize;
    }

   public:
    void insert(string key, v value) {
        int bucketindex = getbucketindex(key);
        mapnode<v>* head = buckets[bucketindex];
        while (head != NULL) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }

        head = buckets[bucketindex];
        mapnode<v>* node = new mapnode<v>(key, value);
        node->next = head;
        buckets[bucketindex] = node;
        count++;
    }
    v remove(string key) {
        int bucketindex = getbucketindex(key);
        mapnode<v>* head = buckets[bucketindex];
        mapnode<v>* pre = NULL;
        while (head != NULL) {
            if (head->key == key) {
                if (pre == NULL) {
                    buckets[bucketindex] = head->next;
                } else {
                    pre->next = head->next;
                }
                v value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            pre = head;
            head = head->next;
        }
        return 0;
    }
    v getvalue(string key) {
        int bucketindex = getbucketindex(key);
        mapnode<v>* head = buckets[bucketindex];
        while (head != NULL) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    int size() {
        return count;
    }

    ~ourmap() {
        for (int i = 0; i < bucketsize; i++) {
            delete buckets[i];
        }
        delete[] buckets;
    }
};

int main() {
    cout << "Code runs" << endl;

    mapnode<int> mn("Rohit", 78);

    ourmap<int> om;

    // om.insert("Rohit", 7);

    // om.insert("Singh", 63);

    // int x = om.getvalue("Rohit");

    // cout << x << endl;

    // cout << om.size() << endl;

    // cout << om.remove("Rohit") << endl;

    // cout << om.size() << endl;

    return 0;
}