#ifndef Pair_h
#define Pair_h

template <typename TKey, typename TValue>
class Pair
{
private:
    TKey KEY;
    TValue VALUE;
    
public:
    
    //Constructor Function with parameters.
    Pair(const TKey &k , TValue v):KEY(k), VALUE(v)
    {};
    
    //Returns reference of KEY.
    TKey& key()
    {
        return KEY;
    }
    
    //Returns reference of VALUE.
    TValue& value()
    {
        return VALUE;
    }
    
    //Returns this object after assigning given value.
    TValue& setValue(TValue &v)
    {
        VALUE = v;
        return *this;
    }
    
    //Checks the right hand side Pair is equal to this one.
    bool operator== (const Pair<TKey, TValue> &right)
    {
        return ( KEY == right.KEY &&
                VALUE == right.VALUE)? true : false;
    }
    
    //Checks the right hand side Pair is NOT equal to this one.
    bool operator!= (const Pair<TKey, TValue> &right)
    {
        return ! operator==(right);
    }
};


#endif
