select 
    customers.customer_id,
    customers.customer_name
from customers
where customers.customer_id in (
    select distinct customer_id
    from orders
    where product_name = 'A'
)
and customers.customer_id in (
    select distinct customer_id
    from orders
    where product_name = 'B'
)
and customers.customer_id not in (
    select distinct customer_id
    from orders
    where product_name = 'C'
)
order by customers.customer_name