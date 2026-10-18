# Write your MySQL query statement below
SELECT V.customer_id,COUNT(V.visit_id) AS count_no_trans
from Visits V
LEFT JOIN Transactions t
ON v.visit_id=t.visit_id
WHERE t.transaction_id is null
GROUP BY v.customer_id