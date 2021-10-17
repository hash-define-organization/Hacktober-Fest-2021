const express = require('express')
const app = express()

const Razorpay = require('razorpay')

const keyId = "rzp_test_6dqOdmR9nSUSSS"
const keySecret = "3HbVVoByMKrtEyDnc4dp3XzA"

app.use(express.json())
app.listen(3000, () => {
    console.log("Listening on port 3000...")
})

const rzpInstance = new Razorpay({
    key_id: keyId,
    key_secret: keySecret
})

app.post("/getOrderId", (req, res) => {

    const options = {

        amount: req.body.amount + "00",
        currency: "INR",
        payment_capture: "1"
    }

    rzpInstance.orders.create(options, (err, order) => {
        const resObj = {
            keyId: keyId,
            orderId: order.id
        }

        res.send(JSON.stringify(resObj))

    })

})

app.post("/updateTransactionStatus", (req, res) => {
    console.log(req.body)
    res.send("success")
})